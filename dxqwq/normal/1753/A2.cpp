// Problem: Make Nonzero Sum (hard version)
// Contest: Codeforces
// URL: https://m3.codeforces.com/contest/1753/problem/A2
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
int a[1000003],b[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int s=0;
		for(int i=1; i<=n; ++i)
			if(a[i]!=0) b[++s]=i;
		if(s%2)
		{
			puts("-1");continue;
		}
		int A=0;
		for(int i=1; i<=s; i+=2)
		if((b[i+1]-b[i])%2)
		{
			if(a[b[i]]==a[b[i+1]]) ++A;
			else A+=2+(b[i-1]+1!=b[i]);
		}
		else
		{
			if(a[b[i]]==a[b[i+1]]) A+=2+(b[i-1]+1!=b[i]);
			else A+=2+(b[i-1]+1!=b[i]);
		}
		printf("%d\n",A+(b[s]!=n));
		for(int i=1; i<=s; i+=2)
		if((b[i+1]-b[i])%2)
		{
			if(a[b[i]]==a[b[i+1]])
			printf("%d %d\n",b[i-1]+1,b[i+1]);
			else
			{
				if(b[i-1]+1!=b[i]) printf("%d %d\n",b[i-1]+1,b[i]-1);
				printf("%d %d\n",b[i],b[i+1]-1);
				printf("%d %d\n",b[i+1],b[i+1]);
			}
		}
		else
		{
			if(a[b[i]]==a[b[i+1]])
			{
				if(b[i-1]+1!=b[i]) printf("%d %d\n",b[i-1]+1,b[i]-1);
				printf("%d %d\n",b[i],b[i+1]-2);
				printf("%d %d\n",b[i+1]-1,b[i+1]);
			}
			else
			{
				if(b[i-1]+1!=b[i]) printf("%d %d\n",b[i-1]+1,b[i]-1);
				printf("%d %d\n",b[i],b[i+1]-1);
				printf("%d %d\n",b[i+1],b[i+1]);
			}
		}
		if(b[s]!=n) printf("%d %d\n",b[s]+1,n);
	}
	return 0;
}