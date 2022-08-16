/***************************************/
#include<cstdio>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
using namespace std;

#define sc(x)  scanf("%c",&x)
#define si(x)  scanf("%d",&x)
#define sl(x)  scanf("%I64d",&x)
#define sf(x)  scanf("%f",&x)
#define sd(x)  scanf("%lf",&x)
#define sld(x) scanf("%Lf",&x)
#define ss(x)  scanf("%s",x)
#define pc(x)  printf("%c",x)
#define pi(x)  printf("%d ",x)
#define pl(x)  printf("%I64d ",x)
#define pf(x)  printf("%f ",x)
#define pd(x)  printf("%lf ",x)
#define pld(x) printf("%Lf ",x)
#define ps(x)  printf("%s ",x)
#define pin(x)  printf("%d\n",x)
#define pln(x)  printf("%I64d\n",x)
#define pfn(x)  printf("%f\n",x)
#define pdn(x)  printf("%lf\n",x)
#define pldn(x) printf("%Lf\n",x)
#define psn(x)  printf("%s\n",x)
#define pn() printf("\n")
#define _p() printf(" ")
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define REV(i,a,b) for(int i=a;i>=b;i--)
#define test int T;si(T);FOR(Test,1,T)
#define MEM(a,v) memset(a,v,sizeof(a))
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define pb push_back
#define pob pop_back
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()
#define mp make_pair
#define fi first
#define se second
#define All(X) X.b(),X.e()
#define ub upper_bound
#define lb lower_bound
#define LL long long
#define LD long double
#define P_Q priority_queue
#define PI pair< int,int >
#define TRI pair< int,PI >
#define TR_I pair< PI,int >
#define VI vector< int >
#define VP vector< PI >
#define VT vector< TRI >
#define MI map< int,int >
#define MP map< PI,int >
#define MS map< string,int >
#define INF (9999999)
#define SZ -1
#define MOD (1<<30)
#define TEST int Test;scanf("%d",&Test);while(Test--)
#define mat_mul(c,a,b,n,mod){long long temp[10][10],k;for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(k=temp[i][j]=0;k<n;k++)temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;for(int i=0;i<n;i++) for(int j=0;j<n;j++)c[i][j]=temp[i][j];}
/*********************************************************/
int dp[205][40005][2],f[205],sum[205],A,B,n;

int fn(int i,int a,int col)
{
	int b=sum[i-1]-a;
	
	if(a+f[i]>A && col==0) return INF;
	if(b+f[i]>B && col==1) return INF;
	if(i==n) return 0;

	if(dp[i][a][col]<0)
	{
		if(col==0)
		{			
			dp[i][a][0]=min(fn(i+1,a+f[i],0),fn(i+1,a+f[i],1)+min(f[i],f[i+1]));
		}
		else
		{
			dp[i][a][1]=min(fn(i+1,a,0)+min(f[i],f[i+1]),fn(i+1,a,1));
		}
	}

	return dp[i][a][col];
}


void solve()
{
	MEM(dp,-1);

	scanf("%d %d %d",&n,&A,&B);
	FOR(i,1,n)
		{si(f[i]);
	sum[i]=sum[i-1]+f[i];}

	if(A+B<sum[n]) {printf("-1\n");return;}

	int ans=(min(fn(1,0,0),fn(1,0,1)));
	printf("%d\n",ans>=INF?-1:ans);
}

int main()
{
	int X;
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	
	//TEST
	{
		solve();
	}

//si(X);
return 0;
}