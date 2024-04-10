// Problem: C. Not Adjacent Matrix
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
int a[1003][1003];
signed main()
{
for(int T=read();T--;)
{
	int n=read();
	if(n==1)
	{
		puts("1");
		
	}
	else if(n==2) puts("-1");
	else
	{
		int cnt=0;
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if((i+j)&1) a[i][j]=++cnt;
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(!((i+j)&1)) a[i][j]=++cnt;
		for(int i=1; i<=n; ++i,puts("")) for(int j=1; j<=n; ++j) printf("%lld ",a[i][j]);
	}
}	
	return 0;
}