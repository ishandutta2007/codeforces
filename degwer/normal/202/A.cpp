#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	char maxi='a'-1;
	int num=0;
	for(int i=0;i<str.size();i++)
	{
		if(maxi==str[i])
		{
			num++;
		}
		if(maxi<str[i])
		{
			maxi=str[i];
			num=1;
		}
	}
	for(int i=0;i<num;i++)
	{
		printf("%c",maxi);
	}
	printf("\n");
}