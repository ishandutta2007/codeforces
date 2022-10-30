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
int n;
const int mod=1e9+7;
int solve(vi a)
{
	int ret=0;
	vi cnt(3);
	bool suc4=0;
	for(auto u:a)
	{
		ret+=u/3;
		cnt[u%3]++;
		if(u%3==1&&u>=4) suc4=1;
	}
	ret-=cnt[0];
	if(n%3==1)
	{//2*2
		if(cnt[2]>=cnt[1]+2)//2 2
			cnt[2]-=2;
		else if(suc4)// 4
		{
			cnt[1]--;
			ret--;
		}
		else if(cnt[2]>=1)//2,1+1
		{
			cnt[2]--;
			cnt[1]-=2;
			ret++;
		}
		else if(cnt[1]>=4)//1+1,1+1
		{
			cnt[1]-=4;
			ret+=2;
		}
		else{// 3+1
			cnt[1]--;
			ret++;
		}
	}
	else if(n%3==2){
		if(cnt[2]) cnt[2]--;
		else{
			cnt[1]-=2;
			ret++;
		}
	}
	int d=min(cnt[1],cnt[2]);
	ret+=d;
	cnt[1]-=d;
	cnt[2]-=d;
	if(cnt[1]) ret+=cnt[1]/3*2;
	if(cnt[2]) ret+=cnt[2];
	return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vi p(n);
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
			p[i]--;
		}
		vi cnt;
		vi vis(n);
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				int cc=0;
				int cur=i;
				while(!vis[cur])
				{
					vis[cur]=1;
					cc++;
					cur=p[cur];
				}
				cnt.push_back(cc);
			}
		}
		dbg(cnt);
		ll ans=1;
		for(int i=0;i<n/3;i++) ans=ans*3%mod;
		if(n%3==2)
			ans=2*ans%mod;
		else if(n%3==1) ans=ans*((mod+1)/3)%mod*4%mod;
		cout<<ans<<" "<<solve(cnt)<<'\n';
	}
}