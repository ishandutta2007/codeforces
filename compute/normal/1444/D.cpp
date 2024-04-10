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
pair<vi,vi> split(vi a)
{
	int n=a.size();
	int sum=accumulate(a.begin(),a.end(),0);
	if(sum%2!=0) return {{},{}};
	vi dp(sum+1,-1);
	dp[0]=0;
	int cur=0;
	for(int i=0;i<n;i++)
	{
		for(int j=cur;j>=0;j--)
		{
			if(dp[j]!=-1&&dp[j+a[i]]==-1)
				dp[j+a[i]]=i;
		}
		cur+=a[i];
	}
	vi vis(n);
	int tar=sum/2;
	if(dp[tar]==-1) return {{},{}};
	while(tar)
	{
		dbg(tar,dp[tar]);
		vis[dp[tar]]=1;
		tar-=a[dp[tar]];
	}
	vi l,r;
	for(int i=0;i<n;i++)
	{
		if(vis[i]) l.push_back(a[i]);
		else r.push_back(a[i]);
	}
	return make_pair(l,r);
}
void solve()
{
	int h;
	cin>>h;
	vi l(h);
	for(int i=0;i<h;i++)
		cin>>l[i];
	int v;
	cin>>v;
	vi p(v);
	for(int i=0;i<v;i++) cin>>p[i];
	if(h!=v)
	{
		cout<<"No\n";
		return;
	}
	auto vl=split(l);
	auto vp=split(p);
	if(!vl.first.size()||!vp.first.size())
	{
		cout<<"No\n";
		return;
	}
	if(vl.first.size()>vl.second.size()) swap(vl.first,vl.second);
	if(vp.first.size()>vp.second.size()) swap(vp.first,vp.second);
	vi R=vl.first,L=vl.second,D=vp.first,U=vp.second;
	vc<pi> lw,up,mid;
	for(int i=0;i<R.size();i++) lw.emplace_back(R[i],U[i]);
	for(int i=0;i<D.size();i++) up.emplace_back(L[i],D[i]);
	sort(lw.begin(),lw.end(),[&](pi &a,pi &b){
		return a.second*b.first<b.second*a.first;
	});
	sort(up.begin(),up.end(),[&](pi &a,pi &b){
		return a.second*b.first<b.second*a.first;
	});
	assert(L.size()-D.size()==U.size()-R.size());
	int rem=L.size()-D.size();
	for(int i=0;i<rem;i++)
		mid.emplace_back(L[i+D.size()],U[i+R.size()]);
	vc<pi> ans;
	int x=0,y=0;
	for(int i=0;i<lw.size();i++)
	{
		x+=lw[i].first;
		ans.emplace_back(x,y);
		y+=lw[i].second;
		ans.emplace_back(x,y);
	}
	for(auto u:mid)
	{
		x-=u.first;
		ans.emplace_back(x,y);
		y+=u.second;
		ans.emplace_back(x,y);
	}
	for(int i=0;i<up.size();i++)
	{
		x-=up[i].first;
		ans.emplace_back(x,y);
		y-=up[i].second;
		ans.emplace_back(x,y);
	}
	cout<<"Yes\n";
	for(auto u:ans) cout<<u.first<<" "<<u.second<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--) solve();
}