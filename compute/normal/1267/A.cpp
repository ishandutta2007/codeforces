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
typedef pair<ll,ll> PII;
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
const ll INF=0x3f3f3f3f3f3f3f3f;

int main()
{
	int n;
	scanf("%d",&n);
	vector<tuple<ll,ll,ll>> all;
	for(int i=0;i<n;i++)
	{
		ll l,r,c;
		scanf("%lld%lld%lld",&l,&r,&c);
		all.emplace_back(l,r,c);
	}
	all.emplace_back(INF,INF,INF);
	sort(all.begin(),all.end());
	priority_queue<PII,vector<PII>,greater<PII>> q;
	ll cur=0,ans=0;
	for(auto& u:all)
	{
		ll l,r,c;
		tie(l,r,c)=u;
		while(!q.empty())
		{
			ll x,R;
			tie(x,R)=q.top();
			if(R<=cur)
				q.pop();
			else if(R<=l)
			{
				ll ti=(R-cur)/x;
				ans+=ti;
				cur+=ti*x;
				q.pop();
			}
			else{
				ll ti=(l-cur)/x;
				ans+=ti;
				cur+=ti*x;
				if(cur+x<=R)
				{
					q.emplace(x-(l-cur),cur+x);
					cur=l;
					break;
				}
				else q.pop();
			}
		}
		cur=l;
		q.emplace(c,r);
	}
	printf("%lld\n",ans);
}