#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=2e5+7;
int p[maxn],q[maxn];
char ans[maxn];
bool ext[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	char cur='a';
	for(int i=1,j;i<=n;i=j)
	{
		k--;
		int sz=0;
		for(j=i;;j++)
		{
			if(!ext[p[j]])
			{
				sz++;
				ext[p[j]]=1;
			}
			else{
				sz--;
				ext[p[j]]=0;
			}
			if(!ext[q[j]])
			{
				sz++;
				ext[q[j]]=1;
			}
			else{
				sz--;
				ext[q[j]]=0;
			}
			if(!sz){
				j++;
				break;
			}
		}
		for(int r=i;r<=j;r++)
			ans[p[r]]=cur;
		if(cur<'z') cur++;
	}
	if(k>0) puts("NO");
	else{
		puts("YES");
		for(int i=1;i<=n;i++) printf("%c",ans[i]);
		puts("");
	}
}