// Problem: C. Felicity is Coming!
// Contest: Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/757/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=1e9+7,p2=1019260817;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int fac[1000003],fa[1000003],v1[1000003],v2[1000003];
pair<int,int> val[1000003];
int find(int x)
{
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y)
{
	x=find(x),y=find(y),fa[x]=y;
}
int g[1000003];
signed main()
{
	int T=read(),n=read();
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=fac[i-1]*i%p;
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int x,base=1,b2=1; T--; base=base*19491001%p,
	b2=b2*1313131%p2)
	{
		x=read();
		int t;
		while(x--)
			t=read(),
			(v1[t]+=base)%=p,
			(v2[t]+=b2)%=p2;
	}
	map<pair<int,int>,int> lst;
	for(int i=1;  i<=n; ++i)
	{
		val[i]=make_pair(v1[i],v2[i]);
		if(lst[val[i]]) merge(lst[val[i]],i);
		lst[val[i]]=i;
	}
	for(int i=1; i<=n; ++i) ++g[find(i)];
	int ans=1;
	for(int i=1; i<=n; ++i) ans=ans*fac[g[i]]%p;
	printf("%lld\n",ans);
	return 0;
}