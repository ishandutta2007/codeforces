// Problem: C. Kleof and the n-thlon
// Contest: Codeforces Round #333 (Div. 1)
// URL: https://codeforces.com/contest/601/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
double p[103][100003];
double s[100003];
signed main()
{
	int n=read(),m=read();
	if(m==1)
	{
		puts("1.0");
		return 0;
	}
	int ss=read();
	for(int i=1; i<=m; ++i) if(i!=ss) p[1][i]=1;
	for(int i=2; i<=n; ++i)
	{
		int x=read();ss+=x;
		for(int j=1; j<=i*m; ++j) s[j]=s[j-1]+p[i-1][j];
		for(int j=i; j<=i*m; ++j)
		{
			if(j<=m+1) if(j>=x) p[i][j]=s[j-1]-p[i-1][j-x];
			else p[i][j]=s[j-1];
			else p[i][j]=s[j-1]-s[j-m-1]-p[i-1][j-x];
			p[i][j]/=(m-1);
		}
	}
	double sum=0;
	for(int i=0; i<ss; ++i) sum+=p[n][i];
	printf("%.10lf\n",sum+1);
	return 0;
}