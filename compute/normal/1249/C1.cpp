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
	int q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		ll ans=n;
		vector<int> a;
		bool two=0;
		while(n)
		{
			a.push_back(n%3);
			if(n%3==2) two=1;
			n/=3;
		}
		if(two)
		{
			ans=0;
			int pos=a.size();
			for(int i=a.size()-1;i>=0;i--)
			{
				if(a[i]==2)
				{
					pos=i+1;
					break;
				}
			}
			while(pos<a.size()&&a[pos]==1) pos++;
			ll cc=1;
			for(int i=0;i<pos;i++)
				cc*=3;
			ans+=cc;
			for(int i=pos+1;i<a.size();i++)
			{
				cc*=3;
				ans+=a[i]*cc;
			}
		}
		cout<<ans<<'\n';
	}
}