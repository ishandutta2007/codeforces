// Problem: B. Tokitsukaze and Meeting
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char s[1000003];
int p[1000003],f[1000003],g[1000003];
int query(int l,int r)
{
	return p[r]-(l<0?0:p[l]);
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read(),N=n*m;
		scanf("%s",s);
		for(int i=0; i<N; ++i) f[i]=g[i]=0;
		p[0]=s[0]-48;
		for(int i=1; i<N; ++i) p[i]=p[i-1]+s[i]-48;
		for(int i=0; i<m; ++i)
			for(int j=i; j<N; j+=m)
				if(s[j]=='1')
				{
					++f[j];
					break;
				} 
		for(int i=0; i<N; ++i)
			if(query(i-m,i)) ++g[i];
		for(int i=1; i<N; ++i) f[i]+=f[i-1];
		for(int i=m; i<N; ++i) g[i]+=g[i-m];
		for(int i=0; i<N; ++i) printf("%d ",f[i]+g[i]);
		puts("");
	}
	return 0;
}