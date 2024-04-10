// Problem: E. Gosha is hunting
// Contest: Codeforces - Codeforces Round #381 (Div. 1)
// URL: https://codeforces.com/problemset/problem/739/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
double a[2003],b[2003],f[2003][2003];
int g[2003][2003];
signed main()
{
	int s=read(),n=read(),m=read();
	for(int i=1; i<=s; ++i) scanf("%lf",&a[i]);
	for(int i=1; i<=s; ++i) scanf("%lf",&b[i]);
	double l=-0.01,r=1.01,lst=-1e18;
	for(int i=0; i<s; ++i) f[i][i+1]=-1e18;
	while(r-l>1e-9)
	{
		double mid=(l+r)*0.5;
		for(int i=1; i<=s; ++i)
		{
			double ax=b[i],ay=0;
			int dx=0,dy=0;
			if(a[i]-a[i]*b[i]>=mid)
				dx=1,ax=a[i]+b[i]-a[i]*b[i]-mid;
			if(a[i]>=mid) 
				dy=1,ay=a[i]-mid;
			f[i][0]=f[i-1][0]+ay,
			g[i][0]=g[i-1][0]+dy;
			for(int j=1; j<=i&&j<=m; ++j)
				if(f[i-1][j-1]+ax>f[i-1][j]+ay)
					f[i][j]=f[i-1][j-1]+ax,
					g[i][j]=g[i-1][j-1]+dx;
				else
					f[i][j]=f[i-1][j]+ay,
					g[i][j]=g[i-1][j]+dy;
		}
		f[s][m]+=mid*g[s][m];
		int k0=g[s][m];
		if(k0==n) printf("%.9lf\n",f[s][m]),exit(0);
		else if(k0<n) r=mid;
		else lst=f[s][m]-(k0-n)*mid,l=mid;
	}
	printf("%.9lf\n",lst);
	return 0;
}