#include<bits/stdc++.h>
using namespace std;
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
bool vis[55][55][2];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n;
void dfs(int r,int c,int num)
{
	vis[r][c][num]=1;
	for(int i=0;i<4;i++)
	{
		int nr=r+dx[i],nc=c+dy[i];
		if(nr<=0||nr>n||nc<=0||nc>n) continue;
		if(vis[nr][nc][num]||maze[nr][nc]=='1') continue;
		dfs(nr,nc,num);
	}
}
int main()
{
	cin>>n;
	int r1,c1,r2,c2;
	cin>>r1>>c1>>r2>>c2;
	for(int i=1;i<=n;i++)
		scanf("%s",maze[i]+1);
	dfs(r1,c1,0);
	if(vis[r2][c2][0])
	{
		cout<<0<<endl;
	}
	else{
		dfs(r2,c2,1);
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int ii=1;ii<=n;ii++)
				{
					for(int jj=1;jj<=n;jj++)
					{
						if(vis[i][j][0]&&vis[ii][jj][1])
						{
							ans=min(ans,(i-ii)*(i-ii)+(j-jj)*(j-jj));
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}