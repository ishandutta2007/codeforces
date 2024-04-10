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
const int maxn=1e5+7;
const int INF=2000;
ll arr[maxn];
int G[200][200];
int dis[200][200];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int var=3*64;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(!arr[i]) i--,n--;
	}
	if(n>var)
	{
		cout<<3<<endl;
		return 0;
	}
	for(int i=0;i<=var;i++)
		for(int j=0;j<=var;j++)
			dis[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			if(arr[i]&arr[j])
				dis[i][j]=dis[j][i]=1;
	}
	memcpy(G,dis,sizeof(G));
	int ans=INF;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				ans=min(ans,G[i][k]+G[k][j]+dis[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	cout<<(ans==INF?-1:ans)<<endl;

}