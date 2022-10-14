// Problem: A. Portal
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/contest/1580/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char s[503][503];
int va[503],vb[503],vc[503];
int a[503][503];
inline int query(int l1,int r1,int l2,int r2)
{
	return a[r1][r2]-a[r1][l2-1]-a[l1-1][r2]+a[l1-1][l2-1];
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i)
			scanf("%s",s[i]+1);
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				a[i][j]=(s[i][j]=='1');
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				a[i][j]+=a[i][j-1];
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				a[i][j]+=a[i-1][j];	
		int ans=1e18;
		for(int i=2; i<n; ++i)
			for(int j=i+2; j<n; ++j)
		{
			for(int k=1; k<=m; ++k) 
				va[k]=query(i,j,k,k),vb[k]=j-i+1-va[k],
				va[k]+=(s[i-1][k]=='0'),va[k]+=(s[j+1][k]=='0');
		vc[2]=1e18;
			for(int k=3; k<m; ++k)
			{
				vc[k]=min(vc[k-1]+va[k],vb[k-2]+va[k-1]+va[k]);
				ans=min(ans,vc[k]+vb[k+1]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}