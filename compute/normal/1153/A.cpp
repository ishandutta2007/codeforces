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
int main()
{
	int n,t;
	cin>>n>>t;
	int cur=0x3f3f3f3f;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int s,d;
		cin>>s>>d;
		if(s>=t)
		{
			if(cur>s)
			{
				cur=s;
				ans=i;
			}
		}
		else {
			if((t-s)%d==0)
			{
				ans=i;break;
			}
			else{
				int gap=(t-s)/d;
				int tt=(gap+1)*d+s;
				if(cur>tt)
				{
					cur=tt;
					ans=i;
				}
			}
		}
	}
	cout<<ans<<endl;
}