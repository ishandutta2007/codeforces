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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		vi x(n),y(n);
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n;i++) cin>>y[i];
		if(n==1)
		{
			cout<<n<<'\n';
			continue;
		}
		sort(x.begin(),x.end());
		vi pre(n),suf(n);
		int cnt=0;
		for(int r=0,l=0;r<n;r++)
		{
			cnt++;
			while(x[r]-x[l]>k) l++,cnt--;
			pre[r]=cnt;
		}
		cnt=0;
		for(int r=n-1,l=n-1;r>=0;r--)
		{
			cnt++;
			while(x[l]-x[r]>k)l--,cnt--;
			suf[r]=cnt;
		}
		for(int i=1;i<n;i++) pre[i]=max(pre[i],pre[i-1]);
		for(int i=n-2;i>=0;i--) suf[i]=max(suf[i],suf[i+1]);
		int ans=0;
		for(int i=0;i<n-1;i++) ans=max(ans,pre[i]+suf[i+1]);
		print(ans);
	}
}