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
const int mod=1e9+7;

int main()
{
	ll l,r;
	cin>>l>>r;
	ll lval=1,rval,len=1;
	ll curl=1,curr=2;
	ll posl=1,posr;
	int vec=1;
	ll ans=0;
	while(1)
	{
		posr=posl+len-1;
		if(vec&1)
		{
			lval=curl;rval=curl+(len-1)*2;
			curl+=len*2;
		}
		else {lval=curr,rval=curr+(len-1)*2;curr+=len*2;};
		if(posl>r) break;
		if(posr>=l)
		{
			ans=(ans+len%mod*(lval%mod)%mod+len%mod*((len-1)%mod)%mod)%mod;
			if(r<posr)
			{
				ll cnt=posr-r;
				ans=(ans-rval%mod*(cnt%mod)%mod+(cnt-1)%mod*(cnt%mod)%mod+mod)%mod;
			}
			if(l>posl)
			{
				ll cnt=l-posl;
				ans=(ans-cnt%mod*(lval%mod)%mod-(cnt-1)%mod*(cnt%mod)%mod+2*mod)%mod;
			}
		}
		dbg(posl,posr,ans,lval,rval,len);
		posl+=len;
		vec++;
		len*=2;
	}
	cout<<ans<<endl;
}