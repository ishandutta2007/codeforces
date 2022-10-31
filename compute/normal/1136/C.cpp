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
int maze[505][505],tar[505][505];
map<int,int> mm[505*2],tt[505*2];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	bool ok=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&maze[i][j]);
			mm[i+j][maze[i][j]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&tar[i][j]);
			tt[i+j][tar[i][j]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!mm[i+j].count(tar[i][j])||mm[i+j][tar[i][j]]!=tt[i+j][tar[i][j]]) ok=0;
		}
	}
	if(ok) puts("YES");
	else puts("NO");
}