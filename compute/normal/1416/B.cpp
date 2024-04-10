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
		int n;
		cin>>n;
		vc<ll> a(n+1);
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%n!=0) print(-1);
		else{
			int tar=sum/n;
			using tp=tuple<int,int,int>;
			vc<tp> ans;
			for(int i=2;i<=n;i++)
			{
				if(a[i]>=i)
				{
					a[1]+=a[i]/i*i;
					ans.emplace_back(i,1,a[i]/i);
					a[i]%=i;
				}
			}
			vc<int> id(n-1);
			for(int i=0;i<n-1;i++) id[i]=i+2;
			sort(id.begin(),id.end(),[&](int x,int y){
				return x-a[x]<y-a[y];
			});
			bool suc=1;
			for(auto u:id)
			{
				if(a[1]>=n) break;
				if(a[1]<u-a[u])
				{
					suc=0;
					break;
				}
				a[1]+=a[u];
				ans.emplace_back(1,u,u-a[u]);
				ans.emplace_back(u,1,1);
				a[u]=0;
			}
			if(!suc)
			{
				print(-1);
				continue;
			}
			else{
				for(int i=2;i<=n;i++)
				{
					if(a[i]>tar)
					{
						ans.emplace_back(1,i,tar+i-a[i]);
						ans.emplace_back(i,1,1);
						a[i]=tar;
					}
				}
				for(int i=2;i<=n;i++)
				{
					if(a[i]<tar)
						ans.emplace_back(1,i,tar-a[i]);
				}
			}
			assert(ans.size()<=3*n);
			print(ans.size());
			for(auto u:ans)
			{
				int i,j,x;
				tie(i,j,x)=u;
				cout<<i<<" "<<j<<" "<<x<<'\n';
			}
		}

	}
}