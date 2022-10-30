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
const int INF=0x3f3f3f3f*2;
const int maxn=2e5+7;
map<int,int> pos;
int arr[maxn],b[maxn];
int pre[maxn],las[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		pos[arr[i]]=i;
	}
	if(n==2)
		printf("%d\n",1);
	else{
		sort(arr+1,arr+1+n);
		vector<int> all;
		all.push_back(arr[2]-arr[1]);
		all.push_back(arr[3]-arr[2]);
		all.push_back(arr[3]-arr[1]);
		int ans=INF;
		for(int i=0;i<3;i++)
		{
			int cur=all[i];
			dbg(i,cur);
			int notok=INF;
			bool ok=1;
			int del=1;
			for(int j=2;j<=n;j++)
			{
				if(arr[j]-arr[j-del]>cur)
				{
					if(j!=n)
						ok=0;
					else 
					{
						if(notok==INF) notok=arr[j];
						else ok=0;
					}
					break;
				}
				else if(arr[j]-arr[j-del]<cur)
				{
					if(notok!=INF) 
					{
						ok=0;
						break;
					}
					else 
					{
						notok=arr[j];
						del=2;
						continue;
					}
				}
				del=1;
			}
			if(ok)
			{
				if(notok!=INF) ans=notok;
				else ans=arr[1];
				break;
			}
		}
		if(ans==INF)
		{
			int delta=arr[3]-arr[2];
			bool ooo=1;
			for(int i=3;i<=n;i++)
			{
				if(arr[i]-arr[i-1]!=delta)
				{
					ooo=0;
					break;
				}
			}
			if(ooo) ans=arr[1];
		}
		printf("%d\n",ans==INF?-1:pos[ans]);
	}
}