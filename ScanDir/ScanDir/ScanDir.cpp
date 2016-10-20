// ScanDir.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <io.h>
#include <string>
#include <fstream> 
using namespace std;

// ��ȱ����ļ���
void dfsFolder(string folderPath, ofstream &fout)
{
	_finddata_t FileInfo;
	string strfind = folderPath + "\\*";
	long Handle = _findfirst(strfind.c_str(), &FileInfo);

	if (Handle == -1L)
	{
		cerr << "can not match the folder path" << endl;
		exit(-1);
	}
	do{
		//�ж��Ƿ�����Ŀ¼
		if (FileInfo.attrib & _A_SUBDIR)    
		{
			// ���ε�ǰĿ¼���ϼ�Ŀ¼
			if( (strcmp(FileInfo.name,".") != 0 ) &&(strcmp(FileInfo.name,"..") != 0))   
			{
				string newPath = folderPath + "\\" + FileInfo.name;
				dfsFolder(newPath, fout);
			}
		}
		else  
		{
			fout << folderPath << "\\" << FileInfo.name  << " "<<endl;
		}
	}while (_findnext(Handle, &FileInfo) == 0);

	_findclose(Handle);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream file3(".\\result.txt");

	dfsFolder("E:\\ScanDir\\ScanDir", file3);

	file3.close();

	return 0;
}

