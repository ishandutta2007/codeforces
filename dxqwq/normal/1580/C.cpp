// Problem: C. Train Maintenance
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/contest/1580/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
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
pair<int,int> a[200003];
int s[200003];
#define mp make_pair
#define fi first
#define se second
int g[403][200003];
int ans[200003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i].fi=read(),a[i].se=read();
	for(int op,x,i=1; i<=m; ++i)
	{
		op=read(),x=read();
		if(op==1)
		{
			//assert(!s[x]);
			s[x]=i;
		}
		else
		{
			long long L=s[x],R=i-1;
			long long ro=a[x].fi+a[x].se;
			if(a[x].fi+a[x].se>=400)
			{
				for(long long l=L+a[x].fi,r=L+ro; l<=R; l+=ro,r+=ro)
					++ans[l],--ans[min(r,R+1)];
			}
			else
			{
				for(long long j=L+a[x].fi; j<L+ro&&j<=R; ++j)
				{
					long long LOOPS=(R-j)/ro;
					//printf("%d %d %d %d\n",j,ro,R,j+(LOOPS+1)*ro);
					++g[ro][j],--g[ro][min(1ll*j+(1ll*LOOPS+1)*ro,1ll+m)];
				}
			}
			s[x]=0;
		}
	}
	for(int i=1; i<=n; ++i) if(s[i])
	{
		long long x=i;
			long long L=s[x],R=m;
			long long ro=a[x].fi+a[x].se;
			if(a[x].fi+a[x].se>=400)
			{
				for(long long l=L+a[x].fi,r=L+ro; l<=R; l+=ro,r+=ro)
					++ans[l],--ans[min(r,R+1)];
			}
			else
			{
				for(long long j=L+a[x].fi; j<L+ro&&j<=R; ++j)
				{
					long long LOOPS=(R-j)/ro;
					//printf("%d %d %d %d\n",j,ro,R,j+(LOOPS+1)*ro);
					++g[ro][j],--g[ro][min(1ll*j+(1ll*LOOPS+1)*ro,1ll+m)];
				}
			}
	}
	for(int i=1; i<=m; ++i) ans[i]+=ans[i-1];
	for(int i=1; i<400; ++i)
	{
		for(int j=1; j<i; ++j) ans[j]+=g[i][j];
		for(int j=i; j<=m; ++j)
			g[i][j]+=g[i][j-i],ans[j]+=g[i][j];
	}
	for(int i=1; i<=m; ++i) printf("%d\n",ans[i]);
	return 0;
}