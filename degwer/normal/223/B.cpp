#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int imo[26][200001];
int main()
{
	string str,mok;
	cin>>str>>mok;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<str.size()+1;j++)
		{
			imo[i][j]=0;
		}
	}
	int pt=0;
	for(int i=0;i<mok.size();i++)
	{
		for(;;)
		{
			if(pt>=str.size())
			{
				printf("No\n");
				return 0;
			}
			if(str[pt]==mok[i])
			{
				imo[str[pt]-'a'][pt]++;
				pt++;
				break;
			}
			pt++;
		}
	}
	pt=str.size()-1;
	for(int i=mok.size()-1;i>=0;i--)
	{
		for(;;)
		{
			if(pt<0)
			{
				printf("No\n");
				return 0;
			}
			if(str[pt]==mok[i])
			{
				imo[str[pt]-'a'][pt+1]--;
				pt--;
				break;
			}
			pt--;
		}
	}
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<=str.size();j++)
		{
			imo[i][j]+=imo[i][j-1];
		}
	}
	bool han=true;
	for(int i=0;i<str.size();i++)
	{
		if(imo[str[i]-'a'][i]<=0)
		{
			han=false;
		}
	}
	if(han)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}