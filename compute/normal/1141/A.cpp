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
int main()
{
	int n,m;
	cin>>n>>m;
	if(m%n!=0)
	{
		cout<<-1<<endl;
	}
	else{
		m=m/n;
		if(m==1) cout<<0<<endl;
		else{
			if(m%2!=0&&m%3!=0)
			{
				cout<<-1<<endl;
			}
			else{
				int ans=0;
				while(m%2==0)
				{
					m/=2;
					ans++;
				}
				while(m%3==0)
				{
					m/=3;
					ans++;
				}
				if(m!=1) cout<<-1<<endl;
				else cout<<ans<<endl;
			}
		}
	}
}