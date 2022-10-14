// Problem: C. Latin Square
// Contest: Codeforces - Codeforces Round #691 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1458/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003][3],p[3],d[3],ans[1003][1003];
char s[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read(),c=0;
		p[0]=0,p[1]=1,p[2]=2,d[0]=d[1]=d[2]=0;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				a[++c][0]=i,a[c][1]=j,a[c][2]=read()-1;
		scanf("%s",s+1);
		for(int i=1,m=strlen(s+1); i<=m; ++i)
		{
			if(s[i]=='U') --d[p[0]];
			else if(s[i]=='D') ++d[p[0]];
			else if(s[i]=='L') --d[p[1]];
			else if(s[i]=='R') ++d[p[1]];
			else if(s[i]=='I') swap(p[1],p[2]);
			else swap(p[0],p[2]);
		}
		for(int i=1; i<=c; ++i)
			ans[(a[i][p[0]]+d[p[0]]%n+n)%n]
			   [(a[i][p[1]]+d[p[1]]%n+n)%n]
			   =(a[i][p[2]]+d[p[2]]%n+n)%n+1;
		for(int i=0; i<n; ++i,puts(""))
			for(int j=0; j<n; ++j)
				printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}