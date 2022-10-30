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
const int INF=0x3f3f3f3f;
const int maxn=3e5+7;
vc<pi> query[maxn];
int tree[maxn];
void add(int x,int v)
{
	while(x<maxn)
	{
		tree[x]+=v;
		x+=x&-x;
	}
}
int ask(int x)
{
	int ret=0;
	while(x)
	{
		ret=ret+tree[x];
		x-=x&-x;
	}
	return ret;
}
int mi[maxn<<2],lz[maxn<<2];
int n;
int op[maxn];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
inline void pushdown(int o)
{
	if(lz[o])
	{
		mi[lson]+=lz[o];
		mi[rson]+=lz[o];
		lz[lson]+=lz[o];
		lz[rson]+=lz[o];
		lz[o]=0;
	}
}
void update(int l,int r,int v,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
	{
		mi[o]+=v;
		lz[o]+=v;
		return;
	}
	int mid=L+R>>1;
	pushdown(o);
	if(l<=mid)
		update(l,r,v,Lson);
	if(r>mid)
		update(l,r,v,Rson);
	mi[o]=min(mi[lson],mi[rson]);
}
void modify(int p,int v,int L=1,int R=n,int o=1)
{
	if(L==R)
	{
		mi[o]=v;
		return;
	}
	int mid=L+R>>1;
	pushdown(o);
	if(p<=mid) modify(p,v,Lson);
	else modify(p,v,Rson);
	mi[o]=min(mi[lson],mi[rson]);
}
int fd(int L=1,int R=n,int o=1)
{
	if(L==R) return L;
	int mid=L+R>>1;
	pushdown(o);
	if(mi[lson]<0)
		return fd(Lson);
	return fd(Rson);
}
void del(int x)
{
	dbg(x);
	add(x,-1);
	modify(x,INF);
	if(x<n)
		update(x+1,n,-1);
	//dbg(x,mi[1],fd());
	if(mi[1]<0)
		del(fd());
}
int main()
{
	int q;
	cin>>n>>q;
	vi a(n+1);
	vi ok(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=a[i]) ok[i]=1;
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		query[x].push_back(make_pair(y,i));
	}
	{
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			if(ok[i]&&a[i]>=i-cur)
			{
				add(i,1);
				modify(i,a[i]-(i-cur));
				dbg(i,cur,a[i]-(i-cur));
				cur++;
			}
			else modify(i,INF);
		}
	}
	dbg(233);
	for(int i=0;i<n;i++)
	{
		dbg(i);
		for(auto u:query[i])
			op[u.second]=ask(n-u.first);
		if(ask(i+1))
			del(i+1);
	}
	for(int i=0;i<q;i++) print(op[i]);
}