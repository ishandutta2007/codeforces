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
const int maxn=2e5+7;
int ans[maxn];
int main()
{
	int n;
	cin>>n;
	if(n%2==0) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			if(i&1)
			{
				ans[i]=i*2-1;
				ans[i+n]=i*2;
			}
			else{
				ans[i]=i*2;
				ans[i+n]=i*2-1;
			}
		}
		for(int i=1;i<=2*n;i++)
			printf("%d%c",ans[i],i==2*n?'\n':' ');
	}
}