// Problem: D. Armchairs
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int a[1000003],b[1000003],c[1000003];
int dp[5003][5003];
signed main()
{
	for(int T=1;T--;)
	{
		int n=read();
		int B=0,C=0;
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=1; i<=n; ++i) if(a[i]==1)
		{
			b[++B]=i;
		}
		else c[++C]=i;
		sort(b+1,b+B+1);
		sort(c+1,c+C+1);
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1; i<=C; ++i) dp[0][i]=0;
		for(int i=1; i<=B; ++i)
		for(int j=1; j<=C; ++j)
		{
			dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(b[i]-c[j]));
		}
		printf("%lld\n",dp[B][C]);
	}
	return 0;
}