// Problem: G. Illumination
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1728/problem/G
// Memory Limit: 512 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
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
	for(int t=x; y; y>>=1,t=1ll*t*t%p) 
		if(y&1) res=1ll*res*t%p;
	return res;
}
int d=read(),n=read(),m=read(),N=1<<m;
int l[1000003],a[33],val[33][33],inv[500003];
int g[100003],sum[100003];
int main()
{
	for(int i=1; i<=500000; ++i) inv[i]=qp(i,p-2);
#define qp(x,y) inv[x]
	for(int i=1; i<=n; ++i) l[i]=read();
	for(int i=0; i<m; ++i) a[i]=read();
	sort(a,a+m);
	for(int S=0; S<N; ++S) g[S]=1;
	for(int l=0; l<m; ++l)
	{
		val[l][l]=1<<l;
		for(int r=l+1; r<m; ++r)
			val[l][r]=val[l][r-1]|(1<<r);
	}
	for(int i=1; i<=n; ++i)
	{
		int pos=l[i],k=lower_bound(a,a+m,pos)-a-1;
		for(int l=k,r=k; l>=0; --l)
		{
			int d=pos-a[l];
			while(r+1<m&&a[r+1]-pos<d) ++r;
			g[(N-1)^val[l+1][r]]
			=1ll*g[(N-1)^val[l+1][r]]*d%p,
			g[(N-1)^val[l][r]]
			=1ll*g[(N-1)^val[l][r]]*qp(d,p-2)%p;
		}
		for(int r=k+1,l=k+1; r<m; ++r)
		{
			int d=a[r]-pos;
			while(l-1>=0&&pos-a[l-1]<=d) --l;
			g[(N-1)^val[l][r-1]]
			=1ll*g[(N-1)^val[l][r-1]]*d%p,
			g[(N-1)^val[l][r]]
			=1ll*g[(N-1)^val[l][r]]*qp(d,p-2)%p;
		}
	}
	for(int i=0; i<m; ++i)
		for(int S=0; S<N; ++S)
			if((S>>i)&1)
				g[S-(1<<i)]=1ll*g[S-(1<<i)]*g[S]%p;
	for(int i=1; i<=n; ++i)
		g[0]=1ll*g[0]*(d+1)%p;
	for(int S=0; S<N; ++S)
		sum[S]=(__builtin_popcount(S)&1)
		?(g[S]?p-g[S]:0):g[S];
	for(int i=0; i<m; ++i)
		for(int S=0; S<N; ++S)
			if((S>>i)&1)
				sum[S]=(sum[S]+sum[S-(1<<i)])%p;
	for(int f,k,ans,T=read(); T--;)
	{
		f=read(),k=lower_bound(a,a+m,f)-a-1,ans=sum[N-1];
		for(int l=k,r=k;l>=0;--l)
		{
			int d=f-a[l];
			while(r+1<m&&a[r+1]-f<d) ++r;
			ans=(ans+(sum[(N-1)^val[l+1][r]]
			-sum[(N-1)^val[l][r]]+p)*(d-1ll))%p;
		}
		for(int r=k+1,l=k+1;r<m;++r)
		{
			int d=a[r]-f;
			while(l-1>=0&&f-a[l-1]<=d) --l;
			ans=(ans+(sum[(N-1)^val[l][r-1]]
			-sum[(N-1)^val[l][r]]+p)*(d-1ll))%p;
		}
		ans=(ans+1ll*d*g[0])%p,printf("%d\n",ans);
	}
	return 0;
}