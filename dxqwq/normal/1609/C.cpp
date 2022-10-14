// Problem: C. Complex Market Analysis
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
const int N=1000000;
bool vis[1000003];
int a[1000003];
int pre[1000003];
int suf[1000003];
signed main()
{
	for(int i=2; i<=N; ++i) if(!vis[i])
	{
		for(int j=2; i*j<=N; ++j) vis[i*j]=1;
	}
	for(int T=read();T--;)
	{
		int n=read(),e=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=1; i<=e; ++i)
		{
			for(int j=i,cnt=0; j<=n; j+=e)
				if(vis[a[j]]) cnt=0;
				else if(a[j]==1) ++cnt;
				else pre[j]=++cnt,cnt=0;
		}
		for(int i=n; i>n-e; --i)
		{
			for(int j=i,cnt=0; j>=1; j-=e)
				if(vis[a[j]]) cnt=0;
				else if(a[j]==1) ++cnt;
				else suf[j]=++cnt,cnt=0;
		}
		int ans=0;
		for(int i=1; i<=n; ++i) if(a[i]>1&&!vis[a[i]]) 
			ans+=pre[i]*suf[i]-1;
		printf("%lld\n",ans);
	}
	return 0;
}