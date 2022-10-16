// Problem: D. Priority Queue
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//lost in rain
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <bitset>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c!='+'&&c!='-')c=getchar();
	return c=='+';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[505],b[505],dp[505][505];
signed main()
{
	int n=read();
	rg(n)int op=re1d();
	if(op)a[i]=1,b[i]=read();gr
	int ans=0;
	const int mod=998244353;
	rg(n)
		if(a[i]==0)continue;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		rg_(j,n)
			if(j==i)
			{
				rg(n)dp[j][i]=dp[j-1][i-1];gr
				continue;
			gr
			if(a[j])
			{
				if(b[j]<b[i]||(b[j]==b[i]&&j<i))
				{
					rg_(k,j)dp[j][k]=dp[j-1][k]+dp[j-1][k-1];
					dp[j][k]%=mod;
					gr
					dp[j][0]=dp[j-1][0];
				gr
				else rg_(k,n+1)dp[j][k-1]=dp[j-1][k-1]*2;dp[j][k-1]%=mod;gr
			gr
			else 
			{
				rg_(k,j)dp[j][k]=dp[j-1][k]+dp[j-1][k+1];dp[j][k]%=mod;gr
				dp[j][0]=dp[j-1][0]*2+dp[j-1][1];dp[j][0]%=mod;
			gr
			if(j>i)dp[j][0]=0;
	//		rg_(k,n+1)odb(dp[j][k-1]);gr puts("");
		gr //puts("");
		int q=0;
		rg_(j,n)q+=dp[n][j];q%=mod;gr
		ans=(ans+q*b[i])%mod;
	//	odb(q);
	gr
	oldl(ans);
	return 0;
}