// Problem: D. Letter Picking
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1728/problem/D
// Memory Limit: 512 MB
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
char s[2003];
int f[2003][2003];
int cmp(char s,char t)
{
	if(s<t) return 1;
	else if(s==t) return 0;
	else return -1;
}
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1; i<n; ++i)
			f[i][i+1]=(s[i]==s[i+1])?0:1;
		for(int le=4; le<=n; le+=2)
			for(int l=1,r=le; r<=n; ++l,++r)
			{
				f[l][r]=-1;
				int g1,g2;
				g1=f[l+2][r];
				if(g1==0) g1=cmp(s[l],s[l+1]);
				g2=f[l+1][r-1];
				if(g2==0) g2=cmp(s[l],s[r]);
				f[l][r]=min(g1,g2);
				g1=f[l][r-2];
				if(g1==0) g1=cmp(s[r],s[r-1]);
				g2=f[l+1][r-1];
				if(g2==0) g2=cmp(s[r],s[l]);
				f[l][r]=max(f[l][r],min(g1,g2));
			}
		if(f[1][n]==1) puts("Alice");
		else if(f[1][n]==0) puts("Draw");
		else puts("Bob");	
	}
	return 0;
}