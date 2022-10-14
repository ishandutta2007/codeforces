// Problem: F1. Alice and Recoloring 1
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/F2
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
bool a[503][503];
bool b[503][503];
bool f[503],g[503];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) a[i][j]=(s[i][j]=='B');
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) b[i][j]=(a[i][j]!=a[i][j-1]);
	for(int i=n; i>=1; --i)
		for(int j=1; j<=m; ++j) b[i][j]=(b[i][j]!=b[i-1][j]); 
	// for(int i=1; i<=n; ++i,puts(""))
		// for(int j=1; j<=m; ++j) printf("%d",b[i][j]);
	int c=b[1][1];
	int ans=0;
	for(int i=2; i<=n; ++i)
		for(int j=2; j<=m; ++j)
			ans+=b[i][j],f[i]^=b[i][j],g[j]^=b[i][j],c^=b[i][j];
	for(int i=2; i<=n; ++i) f[i]^=b[i][1];
	for(int j=2; j<=m; ++j) g[j]^=b[1][j];
	for(int i=2; i<=n; ++i)
		ans+=f[i],c^=f[i];
	for(int j=2; j<=m; ++j)
		ans+=g[j],c^=g[j];
	ans+=c;
	int flg=0;
	for(int i=2; i<=n; ++i)
		for(int j=2; j<=m; ++j)
			if(b[i][j]&&f[i]&&g[j]&&c)
				flg=1;
	printf("%d\n",ans-flg);
	return 0;
}