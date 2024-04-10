// Problem: D. The Number of Imposters
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int fa[1000003],sz[1000003],ssz[1000003];
int find(int x)
{
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n*2; ++i) fa[i]=i,sz[i]=(i<=n),ssz[i]=(i>n);
		for(int i=1; i<=m; ++i)
		{
			int x=read(),y=read();
			char s[13];
			int xx,yy;
			scanf("%s",s+1);
			if(s[1]=='c')
			{
				xx=find(x),yy=find(y);
				if(xx!=yy)
				fa[xx]=yy,sz[yy]+=sz[xx],ssz[yy]+=ssz[xx];
				y+=n,x+=n;
				xx=find(x),yy=find(y);
				if(xx!=yy)
				fa[xx]=yy,sz[yy]+=sz[xx],ssz[yy]+=ssz[xx];
			}
			else
			{
				y+=n;
				xx=find(x),yy=find(y);
				if(xx!=yy)
				fa[xx]=yy,sz[yy]+=sz[xx],ssz[yy]+=ssz[xx];
				y-=n,x+=n;
				xx=find(x),yy=find(y);
				if(xx!=yy)
				fa[xx]=yy,sz[yy]+=sz[xx],ssz[yy]+=ssz[xx];
			}
		}
		bool flg=1;
		int ans=0;
		for(int i=1; i<=n; ++i) if(find(i)==find(i+n))
		{
			flg=0;
			break;
		}
		else
		{
			if(find(i)==i)
			{
				ans+=max(sz[i],ssz[i]);
			}
			if(find(i+n)==i+n)
			{
				ans+=max(sz[i+n],ssz[i+n]);
			}
		}
		if(!flg)
		{
			puts("-1");
			continue;
		} 
		printf("%lld\n",ans/2);
	}
	return 0;
}