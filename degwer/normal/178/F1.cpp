#include<stdio.h>/*
#include "stdafx.h"*/
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int map[2000][2000];
int par[2000];
int ran[2000];
int ren[2000];
void init()
{
	for(int i=0;i<2000;i++)
	{
		par[i]=i;
		ran[i]=0;
		ren[i]=1;
	}
}
int find(int a)
{
	if(par[a]==a)
	{
		return a;
	}
	else
	{
		return par[a]=find(par[a]);
	}
}
void unite(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
	{
		return;
	}
	if(ran[a]>ran[b])
	{
		par[b]=a;
		ren[a]+=ren[b];
	}
	else
	{
		par[a]=b;
		ren[b]+=ren[a];
	}
	if(ran[a]==ran[b])
	{
		ran[b]++;
	}
}
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	vector<string>vec;
	for(int i=0;i<num;i++)
	{
		string str;
		cin>>str;
		vec.push_back(str);
	}
	for(int j=0;j<num;j++)
	{
		for(int k=0;k<num;k++)
		{
			if(j!=k)
			{
				int ret=0;
				for(int l=0;l<min(vec[j].size(),vec[k].size());l++)
				{
					if(vec[j][l]!=vec[k][l])
					{
						break;
					}
					ret++;
				}
				map[j][k]=ret;
			}
		}
	}
	int ko=1;
	for(int l=0;l<num;l++)
	{
		ko*=2;
	}
	int maxi=0;
	for(int m=0;m<ko;m++)
	{
		int bit[20];
		int mon=m;
		int kos=0;
		int zan[20];
		for(int n=0;n<num;n++)
		{
			bit[n]=mon%2;
			if(mon%2==1)
			{
				zan[kos]=n;
				kos++;
			}
			mon/=2;
		}
		if(kos!=gen)
		{
			continue;
		}
		int sum=0;
		for(int o=0;o<gen;o++)
		{
			for(int p=0;p<gen;p++)
			{
				sum+=map[zan[o]][zan[p]];
			}
		}
		maxi=max(maxi,sum);
	}
	printf("%d\n",maxi/2);
}