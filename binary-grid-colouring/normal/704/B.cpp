#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 5010; 
const int M=100010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}

ll x[N],a[N],b[N],c[N],d[N],Next[N];
ll cost(int i,int j)
{
	if(i>j)return abs(x[i]-x[j])+c[i]+b[j];
	else return abs(x[i]-x[j])+d[i]+a[j];
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,s,e;
	n=read();s=read();e=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)d[i]=read();
	Next[s]=e;
	ll ans=cost(s,e);
	for(int i=1;i<=n;i++)
	{
		if(i==s || i==e)continue;
		int u=s;
		int v;
		ll Min=1e18;
		while(u!=e)
		{
			ll tmp=cost(u,i)+cost(i,Next[u])-cost(u,Next[u]);
			if(tmp<Min)
			{
				Min=tmp;
				v=u;
			} 
			u=Next[u];
		}
		ans+=Min;
		Next[i]=Next[v];
		Next[v]=i; 
	}
	printf("%I64d\n",ans);
	return 0;
}