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
ll dfs(int remain,int cur)
{
	if(remain==0) return cur==0;
	return dfs(remain-1,cur+1)+dfs(remain-1,cur-1);
}
int main()
{
	string s,t;
	cin>>s>>t;
	int p=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='+') p++;
		else p--;
	}
	int np=0,nn=0;
	int unk=0;
	for(int i=0;i<t.length();i++)
	{
		if(t[i]=='+') np++;
		else if(t[i]=='-') np--;
		else unk++;
	}
	double ans=1;
	int res=abs(p-np);
	dbg(unk,res);
	if(unk<res) ans=0;
	else{
		ll tot=1;
		for(int i=1;i<=unk;i++) tot=tot*2;
		ll ok=dfs(unk,res);
		dbg(ok,tot);
		ans=(double)ok/tot;
	}
	printf("%.10f\n",ans);
}