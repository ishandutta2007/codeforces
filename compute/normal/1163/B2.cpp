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
int arr[maxn];
int app[maxn];
int num[maxn];
bool ok(int x,int cnt)
{
	if(x==1)
		return app[x]==cnt;
	return (app[x]==1&&app[x-1]==cnt-1)||(app[x]==cnt-1&&app[1]==1);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int cnt=0;
	int ans=1;
	int mx=0;
	for(int i=0;i<n;i++)
	{
		int cur=arr[i];
		if(!num[cur]) 
		{
			num[cur]++;
			cnt++;
			app[num[cur]]++;
			mx=max(mx,num[cur]);
			if(ok(mx,cnt)) ans=i+1;
		}
		else{
			app[num[cur]]--;
			num[cur]++;
			app[num[cur]]++;
			mx=max(mx,num[cur]);
			if(ok(mx,cnt)) ans=i+1;
		}
		mx=max(mx,num[cur]);
		dbg(i,ans,mx);
	}
	printf("%d\n",ans);

}