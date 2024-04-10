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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b*c<a) print(-1);
		else{
			if(d>c)
				print(a);
			else{
				ll L=1,R=1e6,ans=-1;
				auto getv=[&](ll x){
					ll damage=x*a;
					ll t=(x-1)*d;
					ll cc=min(x-1,c/d);
					ll heal=(x-cc-1)*b*c;
					heal+=(1+cc)*cc/2*d*b;
					return damage-heal;
				};
				while(L<=R)
				{
					ll len=(R-L)/3;
					ll lp=L+len,rp=R-len;
					ll lv=getv(lp),rv=getv(rp);
					if(lv>=rv)
					{
						ans=lv;
						R=rp-1;
					}
					else{
						ans=rv;
						L=lp+1;
					}
				}
				assert(ans!=-1);
				print(ans);
			}
		}
	}
}