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
int maze[505][505];
int main()
{
	int n,m;
	cin>>n>>m;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>maze[i][j];
		}
		cur^=maze[i][1];
	}
	pair<int,int> ans={0,0};
	for(int i=1;i<=n;i++)
	{
		int tmp=cur;
		for(int j=1;j<=m;j++)
		{
			tmp=cur^maze[i][1]^maze[i][j];
			if(tmp)
			{
				ans=make_pair(i,j);
				break;
			}
		}
		if(ans.first) break;
	}
	if(!ans.first) puts("NIE");
	else{
		puts("TAK");
		for(int i=1;i<=n;i++)
		{
			if(i==ans.first) cout<<ans.second<<" ";
			else cout<<1<<" ";
		}
		cout<<endl;
	}


}