#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,dp[2010][2010],n,m,K;
int fun(int N,int M)
{
	if(dp[N][M]!=-1) return dp[N][M];
	if(!M) return (ll)(n-N)*K%mod;
	if(N==n) return 0;
	return dp[N][M]=(ll)MOD(fun(N+1,M)+fun(N+1,M-1)-mod)*inv2%mod;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=n-read(),K=read();
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				dp[i][j]=-1;
		printf("%d\n",fun(0,m));
	}
	return 0;
}
//ore no turn,draw!