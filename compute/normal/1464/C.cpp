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
	int n;
	ll T;
	cin>>n>>T;
	string s;
	cin>>s;
	ll v=(1LL<<(s[n-1]-'a'))-(1LL<<(s[n-2]-'a'));
	v-=T;
	v=abs(v);
	vi all;
	for(int i=0;i<n-2;i++) all.push_back(s[i]-'a');
	sort(all.begin(),all.end());
	vi cnt(60);
	for(auto u:all)
	{
		v+=1LL<<u;
		cnt[u+1]++;
	}
	bool suc=1;
	int tot=0;
	for(int i=0;i<60;i++)
	{
		tot+=cnt[i];
		if(v>>i&1)
		{
			if(!tot){
				suc=0;
				break;
			}
			tot--;
		}
		tot/=2;
	}
	if(suc) cout<<"Yes\n";
	else cout<<"No\n";
}