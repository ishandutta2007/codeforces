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
#define pi(x)  printf("%I64d ",x)
#define pf(x)  printf("%f ",x)
#define pd(x)  printf("%lf ",x)
#define pld(x) printf("%Lf ",x)
#define ps(x)  printf("%s ",x)
#define pin(x)  printf("%d\n",x)
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
#define SZ 1005
#define MOD 100
/*********************************************************/
int dp[SZ][SZ][2],X,Y,n,m,cost[SZ][2];

int fn(int c,int x, int col)
{
	if(c==m)
	{
		if(x>=X && x<=Y) return 0;
		else return INF;
	}

	if(dp[c][x][col]>=0) return dp[c][x][col];

	if(x<X)
	{
		dp[c][x][col]=cost[c][col]+fn(c+1,x+1,col);
	}
	else if(x>=Y)
	{
		dp[c][x][col]=cost[c][1-col]+fn(c+1,1,1-col);
	}
	else
	{
		dp[c][x][col]=min(cost[c][col]+fn(c+1,x+1,col),cost[c][1-col]+fn(c+1,1,1-col));
	}

	return dp[c][x][col];

}


int main()
{
	char a[SZ][SZ];

	MEM(dp,-1);

	scanf("%d %d %d %d",&n,&m,&X,&Y);

	FOR(i,0,n-1)
		ss(a[i]);

	FOR(j,0,m-1)
		FOR(i,0,n-1)
	{
		cost[j][0]+=a[i][j]=='.';
		cost[j][1]+=a[i][j]=='#';
	}

	printf("%d",min(fn(0,0,0),fn(0,0,1)));



//si(X);
return 0;
}