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
	int T=1;
	while(T--)
	{
		ll k,l,r,t,x,y;
		cin>>k>>l>>r>>t>>x>>y;
		k-=l;r-=l;
		if(y==x)
		{
			if(k+y<=r||k-x>=0) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else if(y<x){
			ll ans=0;
			if(y+k>r)
			{
				k-=x;
				ans++;
			}
			if(k>=0)
			{
				ll delta=x-y;
				ans+=k/delta;
				ans++;
			}
			if(ans>t) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else {
			if(r-y>=x) cout<<"Yes\n";
			else if(r-y<0){
				ll ans=k/x;
				ans++;
				if(ans>t) cout<<"Yes\n";
				else cout<<"No\n";
			}
			else{
				ll ans=0;
				vi vis(x);
				if(k>=x)
				{
					ll step=k/x;
					ans+=step;
					k%=x;
				}
				assert(k<x);
				bool suc=0;
				dbg(k,ans);
				while(!vis[k])
				{
					if(k>r-y)
					{
						ans++;
						break;
					}
					vis[k]=1;
					k=k+y-x;
					ans++;
					if(k>=x)
					{
						ll step=k/x;
						ans+=step;
						k%=x;
					}
					assert(k<x);
					if(vis[k])
						suc=1;
					dbg(k,ans);
				}
				dbg(ans);
				if(!suc)
				{
					if(ans>t) cout<<"Yes\n";
					else cout<<"No\n";
				}
				else cout<<"Yes\n";
			}
		}
	}
}