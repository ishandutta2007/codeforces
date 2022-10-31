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
const int maxn=1e3+7;
pi pt[maxn];
inline ll dis(pi a,pi b)
{
	return 1LL*(a.first-b.first)*(a.first-b.first)+1LL*(a.second-b.second)*(a.second-b.second);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>pt[i].first>>pt[i].second;
	ll g=0;
	for(int i=1;i<n;i++)
		g=__gcd(dis(pt[0],pt[i]),g);
	vi ans;
	ans.push_back(0);
	for(int i=1;i<n;i++)
	{
		ll d=dis(pt[0],pt[i]);
		d/=g;
		if(d%2==0) ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto u:ans) cout<<u+1<<" ";
	cout<<endl;

}