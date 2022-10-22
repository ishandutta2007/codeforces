#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <iostream>
using namespace std;
#define ll long long
#define longinf 0x3f3f3f3f3f3f3f3f
#define zjhakioi \
freopen("cf.in","r",stdin);\
freopen("cf.out","w",stdout)
#define zjh int
#define ak main
#define ioi ()
ll n,m,s,t;
ll readll(void)
{
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w*=-1),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
ll a[222222],b[222222];
zjh ak ioi {
	//zjhakioi;
	ll n=readll(),m=readll(),ta=readll(),tb=readll(),k=readll();
	if(k>=n||k>=m)return puts("-1"),0;
	for(ll i=1;i<=n;i++)a[i]=readll()+ta;
	for(ll i=1;i<=m;i++)b[i]=readll();
	ll headb=1,tailb=k,heada=0,taila=0,maxx=tailb;
	while(taila<=k&&taila<=n) {
		while(a[taila+1]>b[headb])headb++,tailb++;
		if(tailb>=m)return puts("-1"),0;
		if(tailb>maxx)maxx=tailb;
		taila++,tailb--;
	}
	printf("%lld\n",b[maxx+1]+tb);
	return 0;
}