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
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		int ans=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i-1]+1)
			{
				ans++;
				break;
			}
		}
		cout<<ans<<endl;

	}
}