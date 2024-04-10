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
int ans[maxn];
int main()
{
	ll n,k;
	cin>>n>>k;
	ll re=1LL*(1+k)*k/2;
	n-=re;
	if(n<0)
		puts("NO");
	else{
		int av=n/k;
		int cc=(n+k-1)/k;
		for(int i=1;i<k;i++)
			ans[i]=av;
		ans[k]=cc;
		int tot=0;
		for(int i=1;i<=k;i++)
		{
			ans[i]+=i;
			tot+=ans[i];
		}
		n+=re;
		int res=n-tot;
		for(int i=k;i>=1;i--)
		{
			if(!res) break;
			res--;
			ans[i]++;
		}
		if(k>1&&ans[k]>2*ans[k-1]) puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=k;i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
}