// Problem: C. Tokitsukaze and Two Colorful Tapes
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/C
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
int a[1000003],tmp[1000003];
int vis[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) tmp[read()]=i,vis[i]=0;
		for(int i=1; i<=n; ++i) a[i]=tmp[read()];
		int A=0,q=n-1;
		for(int i=1; i<=n; ++i) if(!vis[i])
		{
			int s=0,x=i;
			while(!vis[x]) ++s,vis[x]=1,x=a[x];
			s>>=1,A+=s;
		}
		int ans=0;
		while(A) ans+=q,--A,q-=2;
		printf("%lld\n",ans*2);
	}
	return 0;
}