// Problem: C. Make Them Equal
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/C
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
char s[1000003];
int c[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) c[i]=0;
		char op[3];
		scanf("%s",op);
		char O=op[0];
		scanf("%s",s+1);
		int A=0,B=0;
		for(int i=1; i<=n; ++i) if(s[i]!=O) A=i,++B,c[i]=1;
		if(!A)
		{
			puts("0");
			continue;
		}
		bool g=0;
		for(int i=1; i<=n; ++i)
		{
			bool f=1;
			for(int j=1; i*j<=n; ++j)
				if(c[i*j]) f=0;
			if(f)
			{
				puts("1");
				printf("%lld\n",i);
				g=1;
				break;
			}
		}
		if(g) continue;
			puts("2");
			printf("%lld %lld\n",n-1,n);
	}
	return 0;
}