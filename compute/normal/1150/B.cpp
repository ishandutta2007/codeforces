#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
char maze[55][55];
int n;
bool check(int x,int y)
{
	if(x==0||y==0||x==n-1||y==n-1) return false;
	if(maze[x][y]=='#'||maze[x-1][y]=='#'||maze[x][y-1]=='#'||maze[x+1][y]=='#'||maze[x][y+1]=='#') return false;
	return true;
}
void op(int x,int y)
{
	maze[x][y]=maze[x-1][y]=maze[x][y-1]=maze[x+1][y]=maze[x][y+1]='#';
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",maze[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(check(i,j))
				op(i,j);
		}
	}
	bool ok=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(maze[i][j]=='.') ok=0;
		}
	}
	if(ok) puts("YES");
	else puts("NO");

}