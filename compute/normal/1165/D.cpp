#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll d;
		vector<ll> p;
		vector<int> di;
		ll ma=0;
		for(int i=0;i<n;i++)
		{
			cin>>d;
			di.push_back(d);
		}
		sort(di.begin(),di.end());
		bool ok=1;
		set<int> dd;
		for(int i=0;i<di.size();i++)
			dd.insert(di[i]);
		for(int i=0;i<di.size();i++)
		{
			for(int j=2;j<=sqrt(di[i]);j++)
			{
				if(di[i]%j!=0) continue;
				if(!dd.count(di[i]/j)||!dd.count(j))
				{
					ok=0;
				}
			}
		}
		ll ans=1LL*di[0]*di[di.size()-1];
		for(auto &p:di) if(ans%p!=0||!dd.count(ans/p)) ok=0;
		if(ok)
			cout<<1LL*di[0]*di[di.size()-1]<<endl;
		else cout<<-1<<endl;
	}
}