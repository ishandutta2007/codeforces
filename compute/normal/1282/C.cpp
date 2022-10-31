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
int tp[maxn];
int t[maxn];
int id[maxn];
ll dp[maxn];
ll ez,hard;int n,T,a,b;
int getcnt(int d,int e,int h)
{
	int ret=0;
	if(1LL*e*a<=d)
		d-=e*a,ret+=e;
	else ret+=d/a,d=0;
	if(1LL*h*b<=d)
		d-=h*b,ret+=h;
	else ret+=d/b;
	return ret;
}
int main()
{
	int m;
	cin>>m;
	while(m--)
	{
		cin>>n>>T>>a>>b;
		ez=0,hard=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>tp[i];
			ez+=(tp[i]==0);
			hard+=tp[i];
		}
		for(int i=1;i<=n;i++) 
		{
			cin>>t[i];
			id[i]=i;
		}
		id[n+1]=n+1;
		t[n+1]=T+1;
		sort(id+1,id+2+n,[&](int i,int j){return t[i]<t[j];});
		int ans=0;
		ll sum=0;
		ans=max(ans,getcnt(t[id[1]]-1,ez,hard));
		for(int i=1;i<=n;i++)
		{
			if(tp[id[i]]==0) ez--;
			else hard--;
			int cost=(tp[id[i]]?b:a);
			sum+=cost;
			int nxt=id[i+1];
			dbg(sum,t[nxt]);
			if(sum<t[nxt])
				ans=max(ans,i+getcnt(t[nxt]-sum-1,ez,hard));
		}
		cout<<ans<<'\n';
	}
}