// Problem: C. Menorah
// Contest: Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/C
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
char s[1000003],t[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s);
		scanf("%s",t);
		int ans=1e18;
		int A=0,B=0,C=0,D=0,E=0;
		for(int i=0; i<n; ++i) if(s[i]=='1') C=1;
		for(int i=0; i<n; ++i)  if(s[i]!=t[i]) if(s[i]=='1')++A; 
		else ++E; else if(s[i]=='1') ++B;
		else ++D;
		if(A==0&&E==0)
		{
			puts("0");
			continue;
		}
		if(A==E&&C) ans=min(ans,A+E);
		if(B==D+1&&C) ans=min(ans,B+D);
		if(ans>1e15) puts("-1"); else printf("%lld\n",ans); 
	}
	return 0;
}