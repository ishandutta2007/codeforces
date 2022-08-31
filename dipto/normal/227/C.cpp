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





long long fn(long long n, LL mod)
{
//if(n==2) return 4;
	if(n==1) return 2%mod;
//if(n==0) return 1;
n-=1;
long long x[2][2]={{3,2},{0,1}};
long long res[2][2]={{1,0},{0,1}};

while(n)
        {
        if(n%2) mat_mul(res,res,x,2,mod)
        mat_mul(x,x,x,2,mod)
        n/=2;
        }

long long ans=(2*res[0][0]+1*res[0][1])%mod;
return ans;
}






void solve()
{LL n,m;
	cin>>n>>m;
	cout<<fn(n,m);

}


int main()
{
	int X;

	//TEST
	{
		solve();
	}

//si(X);
return 0;
}