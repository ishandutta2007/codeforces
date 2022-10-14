// Problem: D. Omkar and the Meaning of Life
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/D
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
int ans[103];
int nxt[103];
signed main()
{
	int n=read();
	if(n==1)
	{
		puts("! 1");
		return 0;
	}
	if(n==2)
	{
		puts("? 1 2");
		fflush(stdout);
		int x=read();
		if(x)
		{
			puts("! 2 1");
		}
		else
		{
			puts("! 1 2");
		}
		return 0;
	}
	int sdt=0,ed=0;
	for(int i=1; i<=n; ++i)
	{
		printf("? ");
		for(int j=1; j<=n; ++j) if(j!=i) printf("2 ");
		else printf("1 ");  
		puts(""),fflush(stdout);
		int res=read();
		if(res&&res<i)
		{
			//a[res]+1=a[i]
			nxt[res]=i;
		}
		else if(res==0)
		{
			sdt=i;
		}
		printf("? ");
		for(int j=1; j<=n; ++j) if(j!=i) printf("1 ");
		else printf("2 ");  
		puts(""),fflush(stdout);
		res=read();
		if(res&&res<i)
		{
			//a[res]-1=a[i]
			nxt[i]=res;
		}
		else if(res==0)
		{
			ed=i;
		}
	}
	int cnt=0;
	for(int i=sdt; i; i=nxt[i]) ans[i]=++cnt;
	printf("! ");
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
	puts("");
	return 0;
}