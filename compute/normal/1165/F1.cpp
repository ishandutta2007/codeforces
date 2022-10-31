#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
typedef pair<int,int> PII;
vector<PII> event;
const int maxn=2e5+7;
int k[maxn];
int hb[maxn];
int n,m;
bool check(int d)
{
	memset(hb,0,sizeof(hb));
	int cnt=0;
	int mon=d;
	for(int i=m-1;i>=0;i--)
	{
		if(event[i].first>d) continue;
		if(i!=m-1)
			cnt-=event[i+1].first-event[i].first;
		cnt=max(cnt,0);
		int cur=event[i].second;
		if(hb[cur]<k[cur]&&cnt<event[i].first)
		{
			int canb=event[i].first-cnt;
			int rel=min(canb,k[cur]-hb[cur]);
			cnt+=rel;
			hb[cur]+=rel;;
		}
	}
	int res=0,r=0;
	for(int i=1;i<=n;i++) res+=k[i]-hb[i],r+=hb[i];
	dbg(d,r,res);
	return r+2*res<=d;

}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	for(int i=0;i<m;i++)
	{
		PII cur;
		scanf("%d%d",&cur.first,&cur.second);
		event.push_back(cur);
	}
	sort(event.begin(),event.end());
	int l=1,r=4e5+7,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);

}