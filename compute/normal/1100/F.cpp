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
const int maxb=21;
const int maxn=5e5+7;
int pre[maxn][maxb];
int lt[maxn][maxb];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,val;i<=n;i++)
	{
		scanf("%d",&val);
		for(int j=0;j<maxb;j++)
		{
			pre[i][j]=pre[i-1][j];
			lt[i][j]=lt[i-1][j];
		}
		int cur=i;
		for(int j=maxb-1;j>=0;j--)
		{
			if(!(val>>j)) continue;
			if(!pre[i][j]) {pre[i][j]=val;lt[i][j]=cur;break;}
			if(lt[i][j]<cur) swap(pre[i][j],val),swap(lt[i][j],cur);
			val^=pre[i][j];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int j=maxb-1;j>=0;j--)
		{
			if(lt[r][j]>=l&&(ans^pre[r][j])>ans) ans^=pre[r][j];
		}
		printf("%d\n",ans);
	}
}