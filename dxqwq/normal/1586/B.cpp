// Problem: B. Omkar and Heavenly Tree
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/B
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
int vis[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		map<int,int> mp;
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) vis[i]=0;
		for(int i=1; i<=m; ++i)
		{
			int x=read(),y=read(),z=read();
			vis[y]=1;
		}
		for(int i=1; i<=n; ++i) if(!vis[i])
		{
			for(int j=1; j<=n; ++j) if(i!=j) printf("%lld %lld\n",i,j);
			break;
		}
		
	}
	return 0;
}