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
#define INF 10000
#define SZ 105
#define MOD 100
/*********************************************************/



int main()
{
	static int a[10];
	int N;
	si(N);

	int top;
	si(top);
	int bottom=7-top;
	bool flag=true;

	while(N--)
	{
		FOR(i,1,6)
			a[i]=0;

		int t;
		si(t);
		a[t]=a[7-t]=1;
		si(t);
		a[t]=a[7-t]=1;

		int j;
		FOR(i,1,6)
			if(!a[i]) {j=i;break;}

		if(bottom != j
		&& bottom != 7-j)
		 flag=false;
	}
/*
	int j=7;
FOR(i,1,6)
	if(!a[i]) {j=i;break;}*/

printf("%s",flag?"YES":"NO");


//si(N);
return 0;
}