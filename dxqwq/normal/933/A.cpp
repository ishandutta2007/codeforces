// Problem: A. A Twisty Movement
// Contest: Codeforces - Codeforces Round #462 (Div. 1)
// URL: https://codeforces.com/contest/933/problem/A/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int f[10003],g[10003],a[100003];
signed main()
{
	int n=read(),ans=0;
	for(int i=1; i<=n; ++i) a[i]=read();
	//no reverse
	for(int i=1; i<=n; ++i)
	{
		if(a[i]==1) f[i]=f[i-1]+1,g[i]=g[i-1];
		else f[i]=f[i-1],g[i]=max(f[i-1],g[i-1])+1;
	}
	ans=max(f[n],g[n]);
	//start with 1
	for(int i=n; i>=1; --i)
	{
		int F=0,G=0,ff=0,gg=0;
		for(int j=i+1; j<=n; ++j)
		{
			if(a[j]==2) ++gg;
			else ff=max(ff,gg)+1;
		}
		ff=max(ff,gg);
		for(int j=i; j>=1; --j){
			if(a[j]==1) ++F;
			else G=max(G,F)+1;
		ans=max(f[j-1]+max(F+ff,G+gg),ans);}
	}
	ans=max(ans,max(f[n],g[n]));
	//start with 1
	for(int i=n; i>=1; --i)
	{
		int F=-1e18,G=0,ff=0,gg=0;
		for(int j=i+1; j<=n; ++j)
		{
			if(a[j]==2) ++gg;
			else ff=max(ff,gg)+1;
		}
		ff=max(ff,gg);
		for(int j=i; j>=1; --j){
			if(a[j]==1) ++F;
			else G=max(G,F+1);
		ans=max(g[j-1]+max(F+ff,G+gg),ans);}
	}
	printf("%lld\n",ans);
	return 0;
}