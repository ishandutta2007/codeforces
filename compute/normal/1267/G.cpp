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
typedef pair<int,int> PII;
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
const int maxn=105;
const int maxv=1e4+7;
double dp[maxn][maxv];
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	int tot=0;
	dp[0][0]=1;
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		tot+=tmp;
		for(int k=i-1;k>=0;k--)
		{
			double w=1.0*(k+1)/(n-k);
			for(int j=tmp;j<maxv;j++)
				dp[k+1][j]+=dp[k][j-tmp]*w;
		}
	}
	double ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<tot;j++)
		{
			if(!dp[i][j]) continue;
			ans+=dp[i][j]*min(1.0*(tot-j)/(n-i),(1.0+0.5*i/(n-i))*x);
		}
	printf("%.12f\n",ans);
}