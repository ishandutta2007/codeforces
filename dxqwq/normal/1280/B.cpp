// Problem: B. Beingawesomeism
// Contest: Codeforces - Codeforces Round #607 (Div. 1)
// URL: https://codeforces.com/contest/1280/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1003][1003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
		int f=1,g=1;
		for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)
		if(s[i][j]=='A') g=0;
		else f=0;
		if(f)
		{puts("0");continue;}
		if(g)
		{puts("MORTAL");continue;}
		{
			int i=1,f=1;
			for(int j=1; j<=m; ++j) if(s[i][j]=='P') f=0;
			if(f) {puts("1");continue;}
		}
		{
			int i=n,f=1;
			for(int j=1; j<=m; ++j) if(s[i][j]=='P') f=0;
			if(f) {puts("1");continue;}
		}
		{
			int i=1,f=1;
			for(int j=1; j<=n; ++j) if(s[j][i]=='P') f=0;
			if(f) {puts("1");continue;}
		}
		{
			int i=m,f=1;
			for(int j=1; j<=n; ++j) if(s[j][i]=='P') f=0;
			if(f) {puts("1");continue;}
		}
		bool F=0;
		for(int i=1; i<=n; ++i)
		{
			int f=1;
			for(int j=1; j<=m; ++j) if(s[i][j]=='P') f=0;
			if(f) {puts("2");F=1;break;}
		}
		if(F) continue;
		for(int i=1; i<=m; ++i)
		{
			int f=1;
			for(int j=1; j<=n; ++j) if(s[j][i]=='P') f=0;
			if(f) {puts("2");F=1;break;}
		}
		if(F) continue;
		if(s[1][1]=='A'){puts("2");continue;}
		if(s[1][m]=='A'){puts("2");continue;}
		if(s[n][1]=='A'){puts("2");continue;}
		if(s[n][m]=='A'){puts("2");continue;}
		int ans=4;
		for(int i=1; i<=n; ++i) if(s[i][1]=='A') ans=3;
		for(int i=1; i<=n; ++i) if(s[i][m]=='A') ans=3;
		for(int i=1; i<=m; ++i) if(s[1][i]=='A') ans=3;
		for(int i=1; i<=m; ++i) if(s[n][i]=='A') ans=3;
		printf("%d\n",ans);
	}
	return 0;
}