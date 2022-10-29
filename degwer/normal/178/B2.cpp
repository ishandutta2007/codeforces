#include<stdio.h>/*
#include "stdafx.h"*/
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int par[2000];
int ran[2000];
void init()
{
	for(int i=0;i<2000;i++)
	{
		par[i]=i;
		ran[i]=0;
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
	}
	else
	{
		par[a]=b;
	}
	if(ran[a]==ran[b])
	{
		ran[b]++;
	}
}
int main()
{
	int cit,way;
	scanf("%d%d",&cit,&way);/*
	vector<vector<int> >vec;
	vector<int>damy;*/
	vector<pair<int,int> >road;/*
	for(int i=0;i<cit;i++)
	{
		vec.push_back(damy);
	}*/
	for(int j=0;j<way;j++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;/*
		vec[za].push_back(zb);
		vec[zb].push_back(za);*/
		road.push_back(make_pair(za,zb));
	}
	int query;
	scanf("%d",&query);
	vector<pair<int,int> >que;
	vector<int>ans;
	for(int k=0;k<query;k++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		que.push_back(make_pair(za,zb));
		ans.push_back(0);
	}
	for(int l=0;l<way;l++)
	{
		init();
		for(int m=0;m<way;m++)
		{
			if(l!=m)
			{
				unite(road[m].first,road[m].second);
			}
		}
		for(int n=0;n<query;n++)
		{
			if(find(que[n].first)!=find(que[n].second))
			{
				ans[n]++;
			}
		}
	}
	for(int o=0;o<query;o++)
	{
		printf("%d\n",ans[o]);
	}
}