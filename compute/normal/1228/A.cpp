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
bool check(int cur)
{
	bool ext[15];
	memset(ext,0,sizeof(ext));
	while(cur)
	{
		if(ext[cur%10]) return 0;
		ext[cur%10]=1;
		cur/=10;
	}
	return 1;
}
int main()
{
	int l,r;
	cin>>l>>r;
	bool ok=0;
	while(l<=r)
	{
		if(check(l))
		{
			ok=1;
			break;
		}
		l++;
	}
	if(ok) cout<<l<<endl;
	else cout<<-1<<endl;
}