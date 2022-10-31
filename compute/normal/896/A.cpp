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
const ll INF=1LL<<60;
const string ori="What are you doing at the end of the world? Are you busy? Will you save us?";
const string p1="What are you doing while sending \"",p2="\"? Are you busy? Will you send \"",p3="\"?";
ll len[maxn];
void db()
{
	len[0]=ori.length();
	for(int i=1;i<maxn;i++)
	{
		len[i]=2*len[i-1]+p1.length()+p2.length()+p3.length();
		if(len[i]>INF) len[i]=INF;
		//dbg(i,len[i]);
	}
}
char solve(int n,ll k)
{
	//dbg(n,k,len[n]);
	if(n==0) return ori[k];
	if(k<p1.length()) return p1[k];
	else if(k<p1.length()+len[n-1]) return solve(n-1,k-p1.length());
	else if(k<p1.length()+len[n-1]+p2.length()) return p2[k-p1.length()-len[n-1]];
	else if(k<len[n]-2) return solve(n-1,k-p1.length()-len[n-1]-p2.length());
	//dbg(k,len[n]-1);
	else if(k==len[n]-2) return '"';
	return '?';
}
int main()
{
	db();
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		ll k;
		cin>>n>>k;
		if(k>len[n]) cout<<'.';
		else cout<<solve(n,k-1);
	}
	cout<<endl;
}