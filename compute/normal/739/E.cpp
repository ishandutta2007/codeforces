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
const double eps=1e-9;
bool gt(double a,double b)
{
	return a>b||abs(a-b)<eps;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,a,b;
	cin>>n>>a>>b;
	vc<double> p(n),u(n);
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++) cin>>u[i];
	double L=-1,R=1,ans;
	int T1=30;
	auto cut=[&](double x,double y){
		double dp=0;int ta=0,tb=0;
		for(int i=0;i<n;i++)
		{
			double pp=p[i]+x,uu=u[i]+y;
			double bt=1-(1-p[i])*(1-u[i])+x+y;
			if(gt(pp,uu)&&gt(pp,bt)&&pp>0)
			{
				dp+=pp;
				ta++;
			}
			else if(gt(uu,bt)&&gt(uu,pp)&&uu>0)
			{
				dp+=uu;
				tb++;
			}
			else if(gt(bt,uu)&&gt(bt,pp)&&bt>0)
			{
				dp+=bt;
				ta++;
				tb++;
			}
		}
		ans=dp-a*x-b*y;
		return make_pair(ta,tb);
	};
	auto cpk=[&](double x){
		double L=-1,R=1;
		int T2=30;
		while(T2--)
		{
			double mid=(L+R)/2;
			pi cur=cut(x,mid);
			if(cur.second<=b)
				L=mid;
			else R=mid;
		}
		pi ret=cut(x,L);
		return ret.first<=a;
	};
	while(T1--)
	{
		double mid=(L+R)/2;
		if(cpk(mid))
			L=mid;
		else R=mid;
	}
	cout<<fixed<<setprecision(7)<<ans<<'\n';
}