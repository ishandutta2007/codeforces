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
const int maxn=2e5+7;
int v[maxn];
ll pre[maxn];
struct L{
	ll a,b;
	inline ll get(ll x)//ax+b
	{return a*x+b;}
};
inline bool down(L a,L b, L c)
{
	return (a.a-b.a)*(c.b-b.b)>=(b.a-c.a)*(b.b-a.b);
}
struct ConvexHull{
	L dq[maxn];
	int sz;
	void clear(){sz=0;}
	void push(L x,int t)
	{
		if(t==1) while(sz>=2&&down(x,dq[sz],dq[sz-1])) sz--;//x.a
		else while(sz>=2&&down(dq[sz-1],dq[sz],x)) sz--;//x.a
		dq[++sz]=x;
	}
	ll get(ll x)
	{
		ll L=1,R=sz,ret=-1;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(mid==1||dq[mid].get(x)>=dq[mid-1].get(x))
			{
				ret=mid;
				L=mid+1;
			}
			else R=mid-1;
		}
		return dq[ret].get(x);
	}
}q;
int main()
{
	int n;
	cin>>n;
	ll tot=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];
		tot+=1LL*i*v[i];
	}
	ll ans=tot;
	for(int i=1;i<=n;i++)
	{
		q.push(L{i,-pre[i-1]},1);
		ll cur=q.get(v[i])-1LL*i*v[i]+pre[i-1];
		ans=max(ans,tot+cur);
	}
	q.clear();
	for(int i=n;i>=1;i--)
	{
		q.push(L{i,-pre[i]},2);
		ll cur=q.get(v[i])-1LL*i*v[i]+pre[i];
		ans=max(ans,tot+cur);
	}
	cout<<ans<<'\n';
}