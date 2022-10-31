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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi aa(n);
		ll sum=0,xx=0;
		for(int i=0;i<n;i++) 
		{
			cin>>aa[i];
			sum+=aa[i];
			xx^=aa[i];
		}
		ll a;
		const int var=52;
		if(sum&1)
		{
			a=(1LL<<var)-1;
			sum+=a;
			xx^=a;
		}
		else{
			a=(1LL<<var)-2;
			sum+=a;
			xx^=a;
		}
		dbg(sum,xx);
		ll delta=2*xx-sum;
		assert(delta>=0&&delta%2==0);
		cout<<3<<'\n';
		cout<<a<<" "<<delta/2<<" "<<delta/2<<'\n';

	}
}