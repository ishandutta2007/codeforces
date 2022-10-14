// Problem: D. Clues
// Contest: Codeforces - Codeforces Round #110 (Div. 1)
// URL: https://codeforces.com/contest/156/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n=read(),m=read(),p=read();
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int fa[100003],a[100003];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
signed main()
{
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int u,v; m--;)
		u=find(read()),v=find(read()),fa[u]=v;
	for(int i=1; i<=n; ++i) ++a[find(i)];
	int prod=1,s=0;
	for(int i=1; i<=n; ++i) if(a[i]) ++s,prod=prod*a[i]%p;
	if(s==1) printf("%lld\n",1%p);
	else printf("%lld\n",qp(n,s-2)*prod%p);
	return 0;
}