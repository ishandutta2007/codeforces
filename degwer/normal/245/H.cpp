#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int map[5000][5000];
int rui[5001][5001];
int main()
{
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		for(int j=0;j<str.size();j++)
		{
			if(i-j<0||i+j>=str.size())
			{
				break;
			}
			if(str[i-j]==str[i+j])
			{
				map[i-j][i+j]=1;
			}
			else
			{
				break;
			}
		}
	}
	for(int i=0;i<str.size()-1;i++)
	{
		for(int j=0;j<str.size();j++)
		{
			if(i-j<0||i+j+1>=str.size())
			{
				break;
			}
			if(str[i-j]==str[i+j+1])
			{
				map[i-j][i+j+1]=1;
			}
			else
			{
				break;
			}
		}
	}
	for(int i=0;i<str.size();i++)
	{
		for(int j=0;j<str.size();j++)
		{
			rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+map[i][j];
		}
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		printf("%d\n",rui[str.size()][zb]-rui[za-1][zb]);
	}
}