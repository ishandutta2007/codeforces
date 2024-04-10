#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
const ll var=1e18;
ll check(ll x)
{
	int r=0;
	ll sv=x;
	while(sv)
	{
		sv/=10;
		r++;
	}
	//dbg(x,r);
	ll cnt=9;
	ll ret=0;
	ll cur=0;
	ll tot=0;
	for(int i=1;i<r;i++)
	{
		tot+=cnt;
		ret+=(cur+i+cnt*i+cur)*cnt/2;
		cur+=1LL*cnt*i;
		cnt*=10;
	}
	dbg(x,tot,ret,r);
	ret+=(cur+r+r*(x-tot)+cur)*(x-tot)/2;
	dbg(x,tot,ret);
	return ret;
}
int solve(ll x)
{
	ll L=1,R=1e9,pos=-1;
	while(L<=R)
	{
		ll mid=L+R>>1;
		if(check(mid)>=x)
		{
			pos=mid;
			R=mid-1;
		}
		else L=mid+1;
	}
	dbg(pos);
	ll delta=x-check(pos-1);
	ll cnt=9,step=1,tot=0;
	while(delta>cnt*step)
	{
		//dbg(delta,cnt,step);
		delta-=cnt*step;
		tot+=cnt;
		cnt*=10;
		step++;
	}
	tot+=delta/step;
	if(delta%step!=0) tot++;
	//dbg(tot,delta,step,delta%step);
	int tar=delta%step;
	if(!tar) tar=step;
	tar=step-tar;
	while(tar)
	{
		tot/=10;
		tar--;
	}
	assert(tot);
	return tot%10;
}
int main()
{
	//db();
	int q;ll k;
	cin>>q;
	while(q--)
	{
		cin>>k;
		cout<<solve(k)<<endl;
	}
}