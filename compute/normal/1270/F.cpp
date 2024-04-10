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
const int maxn=2e5+7;
int pre[maxn];
int cnt[maxn*450];
int main()
{
	string s;
	cin>>s;
	const int var=sqrt(s.length());
	for(int i=1;i<=s.length();i++)
		pre[i]=pre[i-1]+(s[i-1]-'0');
	ll ans=0;
	for(int i=1;i<var;i++)
	{
		int vd=s.length()*var;
		cnt[vd]=1;
		for(int j=1;j<=s.length();j++)
		{
			int cur=j-i*pre[j];
			ans+=cnt[cur+vd];
			cnt[cur+vd]++;
		}
		for(int j=1;j<=s.length();j++)
			cnt[j-i*pre[j]+vd]=0;
	}
	for(int c=1;c<=s.length()/var+1;c++)
	{
		int l=1,r=1;
		for(int i=1;i<=s.length();i++)
		{
			while(r<=s.length()&&pre[r]-pre[i-1]<=c)
				r++;
			while(l<s.length()&&pre[l]-pre[i-1]<c) l++;
			if(pre[l]-pre[i-1]==c)
			{
				int lenl=l-i+1,lenr=r-i;
				int kl=(lenl+c-1)/c,kr=lenr/c;
				kl=max(kl,var);
				ans+=max(0,kr-kl+1);
			}
		}
	}
	cout<<ans<<'\n';
}