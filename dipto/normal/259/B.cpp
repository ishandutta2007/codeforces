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
#define INF (1000000000)
#define SZ 100000
#define MOD (1<<30)
#define TEST int Test;scanf("%d",&Test);while(Test--)
#define mat_mul(c,a,b,n,mod){long long temp[10][10],k;for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(k=temp[i][j]=0;k<n;k++)temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;for(int i=0;i<n;i++) for(int j=0;j<n;j++)c[i][j]=temp[i][j];}
/*********************************************************/
int a[3][3];

bool validate()
{
	FOR(i,0,2)
		FOR(j,0,2)
		if(a[i][j]<=0) return false;

	int sum=a[0][0]+a[0][1]+a[0][2];

	FOR(i,0,2)
	{
		int s=0;
		FOR(j,0,2)
			s+=a[i][j];
		if(s!=sum) return false;

	}

	FOR(j,0,2)
	{
		int s=0;
		FOR(i,0,2)
			s+=a[i][j];
		if(s!=sum) return false;

	}

	if(a[0][0]+a[1][1]+a[2][2]!= sum) return false;
	if(a[0][2]+a[1][1]+a[2][0]!= sum) return false;

	return true;
}


void solve()
{
	FOR(i,0,2)
		FOR(j,0,2)
		scanf("%d",&a[i][j]);

	FOR(i,1,100000)
	{
		a[0][0]=i;
		int sum=a[0][0]+a[0][1]+a[0][2];
		a[1][1]=sum-a[1][0]-a[1][2];
		a[2][2]=sum-a[2][0]-a[2][1];

		if(validate())
		{
			FOR(i,0,2)
			{		FOR(j,0,2)
					printf("%d ",a[i][j]);
				printf("\n");
			}
		}
	}

}

int main()
{
	//freopen ("input.txt","r",stdin);
	//freopen ("output.txt","w",stdout);

	//TEST
	{
		solve();
	}

return 0;
}