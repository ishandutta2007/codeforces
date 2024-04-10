// Problem: C. Cutting Rectangle
// Contest: Codeforces - Tinkoff Internship Warmup Round 2018 and Codeforces Round #475 (Div. 1)
// URL: https://codeforces.com/contest/963/problem/C
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
int x[1000003],y[1000003],z[1000003];
vector<int> a[200003];
signed main()
{
	int n=read(),gg=0;
	map<int,int> X,Y;
	int A=0,B=0;
	for(int i=1; i<=n; ++i)
	{
		x[i]=read(),y[i]=read(),z[i]=read();
		if(!X[x[i]]) X[x[i]]=++A;
		if(!Y[y[i]]) Y[y[i]]=++B;
		x[i]=X[x[i]],y[i]=Y[y[i]];
		gg=__gcd(gg,z[i]);
	}
	if(A*B!=n) puts("0"),exit(0);
	for(int i=1; i<=A; ++i)
		a[i].resize(B+3);
	for(int i=1; i<=n; ++i)
		a[x[i]][y[i]]=z[i];
	int ans=0;
	for(int i=1; i<A; ++i)
		for(int j=2; j<=B; ++j)
			if((__int128)a[i][1]*a[i+1][j]!=
			   (__int128)a[i][j]*a[i+1][1])
			   	puts("0"),exit(0);
			
	for(int i=1; i*i<=gg; ++i)
		if(gg%i==0) ++ans,ans+=(i*i!=gg);
	printf("%lld\n",ans);
	return 0;
}