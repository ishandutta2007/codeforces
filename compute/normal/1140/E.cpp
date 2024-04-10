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
const int maxn=2e5+7;
const int mod=998244353;
int arr[2][maxn];
int n,k;
long long dp[maxn][2];
long long calc(int cnt,bool type)
{
	assert(cnt>=0);
	if(dp[cnt][type]!=-1) return dp[cnt][type];
	if(cnt==0)
	{
		if(type) return 0;
		return 1;
	}
	long long ret=1;
	if(cnt%2==1)
	{
		if(type==0)
		{
			ret=2LL*calc(cnt/2,1)*calc(cnt/2,0)%mod+(k-2)*(calc(cnt/2,0)*calc(cnt/2,0)%mod)%mod;
			ret%=mod;
		}
		else{
			ret=calc(cnt/2,1)*calc(cnt/2,1)%mod+(k-1)*calc(cnt/2,0)%mod*calc(cnt/2,0)%mod;
			ret%=mod;
		}
	}
	else{
		if(type==0)
		{
			ret=calc(cnt-1,1)+calc(cnt-1,0)*(k-2)%mod;
			ret%=mod;
		}
		else{
			ret=calc(cnt-1,0)*(k-1)%mod;
		}
	}
	return dp[cnt][type]=ret;
}
long long solve(int cur)
{
	dbg(cur);
	long long ret=1;
	int cnt=0;
	int fi=-1;
	for(int i=0;i<(n+(cur==0))/2;i++)
	{
		dbg(arr[cur][i]);
		if(arr[cur][i]==-1) cnt++;
		else{
			if(cnt)
			{
				if(fi!=-1)
					ret=ret*calc(cnt,arr[cur][i]==fi)%mod;
				else{
					ret=ret*((k-1)*calc(cnt-1,0)%mod+calc(cnt-1,1)%mod)%mod;
				}
			}
			else{
				if(fi==arr[cur][i]) return 0;
			}
			fi=arr[cur][i];
			cnt=0;
		}
		dbg(ret);
	}
	if(cnt)
	{
		if(fi!=-1)
			ret=ret*((k-1)*calc(cnt-1,0)%mod+calc(cnt-1,1)%mod)%mod;
		else{
			if(cnt==1) ret=ret*k%mod;
			else ret=ret*(1LL*k*calc(cnt-2,1)%mod+(1LL*k*k-k)*calc(cnt-2,0)%mod)%mod;
		}
	}
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&arr[i&1][i/2]);
	long long ans=0;
	ans=solve(0)*solve(1)%mod;
	printf("%lld\n",ans);
}