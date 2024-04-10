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
typedef vector<ll> vi;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vi cf(n);
	cf[0]=a[0];
	for(int i=1;i<n;i++) cf[i]=a[i]-a[i-1];
	ll sum=0;
	for(int i=1;i<n;i++)
	{
		if(cf[i]>0) sum+=cf[i];
	}
	print(max((sum+cf[0])/2,sum+cf[0]-(sum+cf[0])/2));
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		l--,r--;
		if(l==0)
			cf[0]+=x;
		else{
			if(cf[l]>0) sum-=cf[l];
			cf[l]+=x;
			if(cf[l]>0) sum+=cf[l];
		}
		if(r+1<n)
		{
			if(cf[r+1]>0) sum-=cf[r+1];
			cf[r+1]-=x;
			if(cf[r+1]>0) sum+=cf[r+1];
		}
		print(max((sum+cf[0])/2,sum+cf[0]-(sum+cf[0])/2));
	}
	

}