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
const int maxn=5e3+7;
int a[maxn],b[maxn],c[maxn];
int mi[maxn],mx[maxn];
vi G[maxn];
int last[maxn];
bool vis[maxn];
int dp[maxn][maxn];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i]>>c[i];
		last[i]=i;
	}
	for(int i=n;i>=1;i--)
		mi[i]=max(a[i],max(0,mi[i+1]-b[i]));
	mx[1]=k;
	for(int i=2;i<=n+1;i++)
		mx[i]=mx[i-1]+b[i-1];
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		last[v]=max(last[v],u);
	}
	for(int i=1;i<=n;i++) G[last[i]].push_back(i);
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		dbg(i,mi[i],mx[i]);
		if(mx[i]<mi[i]) ok=0;
	}
	if(!ok)
	{
		cout<<-1<<endl;
		return 0;
	}
	int ans=0;
	memset(dp,-0x3f,sizeof(dp));
	dp[0][k]=0;
	for(int i=1;i<=n;i++)
	{
		vi gain;
		for(auto v:G[i])
			gain.push_back(c[v]);
		sort(gain.begin(),gain.end(),greater<int>());
		for(int j=1;j<gain.size();j++) gain[j]+=gain[j-1];
		for(int k=mi[i+1];k<=mx[i+1];k++)
		{
			if(k>=b[i])
				dp[i][k]=dp[i-1][k-b[i]];
			for(int j=0;j<G[i].size();j++)
			{
				if(k-b[i]+j+1<0) continue;
				dp[i][k]=max(dp[i][k],dp[i-1][k-b[i]+j+1]+gain[j]);
			}
			dbg(i,k,dp[i][k]);
		}

	}
	for(int i=0;i<=mx[n+1];i++) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;

}