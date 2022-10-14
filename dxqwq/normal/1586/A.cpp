// Problem: A. Windblume Ode
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/A
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
bool f[1000003];
int a[1000003];
signed main()
{
	int N=20000;
	for(int i=2; i<=N; ++i) if(!f[i])
		for(int j=2; i*j<=N; ++j) f[i*j]=1;
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int s=0;
		for(int i=1; i<=n; ++i) s+=a[i];
		if(f[s]) 
		{
			printf("%lld\n",n);
			for(int i=1; i<=n;++i) printf("%lld ",i);
			puts("");
		}
		else 
		{
			for(int i=1; i<=n; ++i) if(a[i]&1)
			{
				printf("%lld\n",n-1);
				for(int j=1; j<=n; ++j) if(i!=j) printf("%lld ",j);
				puts("");break;
			}
			
		}
	}
	return 0;
}