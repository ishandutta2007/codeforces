#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=1005;
int arr[maxn][maxn];
vector<int> row[maxn],col[maxn];
int getid(int x,int i,int type)
{
	if(type==1)
	{
		return lower_bound(row[i].begin(),row[i].end(),x)-row[i].begin();
	}
	else {
		return lower_bound(col[i].begin(),col[i].end(),x)-col[i].begin();
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			row[i].push_back(arr[i][j]);
		}
		sort(row[i].begin(),row[i].end());
		row[i].erase(unique(row[i].begin(),row[i].end()),row[i].end());
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			col[j].push_back(arr[i][j]);
		}
		sort(col[j].begin(),col[j].end());
		col[j].erase(unique(col[j].begin(),col[j].end()),col[j].end());
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int ans;
			int cur=arr[i][j];
			int dx=getid(cur,i,1)+(col[j].size()-1-getid(cur,j,2));
			int dy=getid(cur,j,2)+(row[i].size()-1-getid(cur,i,1));
			ans=max(dx,dy)+1;
			ans=max(ans,max((int)col[j].size(),(int)row[i].size()));
			printf("%d ",ans);
		}
		puts("");
	}

}