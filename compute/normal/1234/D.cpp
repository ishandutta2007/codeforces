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
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
const int maxn=1e5+7;
int sum[maxn<<2][26];
string s;
void update(int p,int tp,int val,int L=1,int R=s.length(),int o=1)
{
	if(L==R)
	{
		sum[o][tp]+=val;
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,tp,val,Lson);
	else update(p,tp,val,Rson);
	sum[o][tp]=sum[lson][tp]+sum[rson][tp];
}
int query(int l,int r,int tp,int L=1,int R=s.length(),int o=1)
{
	if(l<=L&&r>=R)
		return sum[o][tp];
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid) ret+=query(l,r,tp,Lson);
	if(r>mid) ret+=query(l,r,tp,Rson);
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	for(int i=0;i<s.length();i++)
		update(i+1,s[i]-'a',1);
	int q;
	cin>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int pos;
			char c[5];
			cin>>pos>>c;
			update(pos,s[pos-1]-'a',-1);
			s[pos-1]=c[0];
			update(pos,s[pos-1]-'a',1);
		}
		else{
			int l,r;
			cin>>l>>r;
			int ans=0;
			for(int i=0;i<26;i++)
				if(query(l,r,i)) ans++;
			cout<<ans<<'\n';
		}
	}
}