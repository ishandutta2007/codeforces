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
#define INF 1000000000
#define SZ 5001
#define MOD 1010000000
#define TEST int Test;scanf("%d",&Test);while(Test--)
#define mat_mul(c,a,b,n,mod){long long temp[10][10],k;for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(k=temp[i][j]=0;k<n;k++)temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;for(int i=0;i<n;i++) for(int j=0;j<n;j++)c[i][j]=temp[i][j];}
/*********************************************************/


int a[105][10005];
int dp[105][10005];
int dp2[105][10005];
char temp[10005];

void solve()
{int n,m;
	cin>>n>>m;

	FOR(i,0,n-1)
	{ss(temp);
		FOR(j,0,m-1)
	{
		
		a[i][j]=temp[j]=='1';
	}

	}
	FOR(i,0,n-1)
	{
		int j=0;
		for(j=m-1;j>=0;j--)
		{
			if(a[i][j]==1) break;
		}

		if(j==-1) {cout<<"-1";return;}

		dp[i][0]=a[i][0]==1?0:(m-j);

		FOR(j,1,m-1)
			dp[i][j]=a[i][j]==1?0:dp[i][j-1]+1;
	}

	FOR(i,0,n-1)
	{
		int j=0;
		for(j=0;j<m;j++)
		{
			if(a[i][j]==1) break;
		}

		//if(j==-1) {cout<<"-1";return;}

		dp2[i][m-1]=a[i][m-1]==1?0:j+1;

		REV(j,m-2,0)
			dp2[i][j]=a[i][j]==1?0:dp2[i][j+1]+1;
	}

	int ans=INF;

	FOR(j,0,m-1)
	{
		int move=0;
	FOR(i,0,n-1)		
	{
		int t=min(dp[i][j],dp2[i][j]);
		move+=t;
	}

	ans=min(ans,move);
	}

	cout<<ans;
}


int main()
{
	int X;

	//TEST
	{
		solve();
	}

si(X);
return 0;
}