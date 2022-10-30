#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
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
const int mod=998244353;
const int maxn=1e6+7;
ll dp[maxn];
int d[maxn],e[maxn];

int prime[maxn] = {0}, phi[maxn] = {0}, tot;

void euler()
{
    phi[1] = 1;
	d[1]=1;
    for (int i = 2; i < maxn; i++)
    {
        if (!phi[i])
        {
			d[i]=2;
			e[i]=1;
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++)
        {
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
				d[i*prime[j]]=d[i]/(e[i]+1)*(e[i]+2);
				e[i*prime[j]]=e[i]+1;
                break;
            }
			e[i*prime[j]]=1;
			d[i*prime[j]]=d[i]*2;
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	euler();
	int n;
	cin>>n;
	ll sum=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(sum+d[i])%mod;
		sum=(sum+dp[i])%mod;
	}
	print(dp[n]);
}