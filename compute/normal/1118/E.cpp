#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	long long n,k;
	scanf("%lld%lld",&n,&k);
	if(n>k*k-k) puts("NO");
	else{
		puts("YES");
		int cnt=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				printf("%d %d\n",i,j);
				cnt++;
				if(cnt==n) break;
				printf("%d %d\n",j,i);
				cnt++;
				if(cnt==n) break;
			}
			if(cnt==n) break;
		}
	}
}