#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=5e5+7;
int mx[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n,k;
void modify(int p,int v,int L=0,int R=n,int o=1)
{
	if(L==R)
	{
		mx[o]=v;
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) modify(p,v,Lson);
	else modify(p,v,Rson);
	mx[o]=max(mx[lson],mx[rson]);
}
int query(int l,int r,int L=0,int R=n,int o=1)
{
	if(l<=L&&r>=R)
		return mx[o];
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid)
		ret=max(ret,query(l,r,Lson));
	if(r>mid) ret=max(ret,query(l,r,Rson));
	return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>k;
	vi a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]-=i;
	}
	vi all=a;
	mkuni(all);
	auto getid=[&](int x){
		return lower_bound(all.begin(),all.end(),x)-all.begin();
	};
	for(int i=1;i<=n;i++) a[i]=getid(a[i]);
	vi b(k);
	vi lock(n+1);
	bool suc=1;
	for(int i=0;i<k;i++)
	{
		cin>>b[i];
		lock[b[i]]=1;
		if(i&&a[b[i]]<a[b[i-1]]) suc=0;
	}
	if(!suc)
	{
		print(-1);
		return 0;
	}
	int ans=0;
	int pre=0;
	for(int i=1;i<=n;i++)
	{
		if(lock[i])
		{
			int cur=query(0,a[i])+1;
			for(int j=pre;j<i;j++) modify(a[j],0);
			modify(a[i],cur);
			pre=i;
		}
		else{
			int cur=query(0,a[i])+1;
			modify(a[i],cur);
		}
	}
	cout<<n-query(0,n)<<'\n';
}