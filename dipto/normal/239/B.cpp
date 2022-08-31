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
#define SZ -1
#define MOD (1<<30)
#define TEST int Test;scanf("%d",&Test);while(Test--)
#define mat_mul(c,a,b,n,mod){long long temp[10][10],k;for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(k=temp[i][j]=0;k<n;k++)temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;for(int i=0;i<n;i++) for(int j=0;j<n;j++)c[i][j]=temp[i][j];}
/*********************************************************/
char a[500],b[500];
int cnt[10],l;

void solve(int cp,char dp,int prevInd, char prev)
{
	if(cp==-1 || cp==l) return;

	if(a[cp]>='0' && a[cp]<='9')
	{
		cnt[(int)(a[cp]-'0')]++;
		
		if(a[cp]=='0')
		{
			a[cp]='#';

		}
		else
			a[cp]--;

		prev=a[cp];
		prevInd=cp;	
	}
	else if(a[cp]=='>' || a[cp]=='<')
	{
		if(prev=='>' || prev=='<')
			a[prevInd]='#';
		dp=a[cp];
		prev=a[cp];
		prevInd=cp;
	}

	solve(cp+(dp=='>'?1:-1),dp,prevInd,prev);
	
}

int main()
{
	int X,n,q;
	si(n);si(q);
	ss(b);
	
	while(q--)
	{
		int L,R;
		si(L);si(R);
		l=0;
		for(int i=L-1;i<=R-1;i++)
			a[l++]=b[i];
		FOR(i,0,9)
			cnt[i]=0;
		
		solve(0,'>',-1,'*');

		FOR(i,0,9)
			printf("%d ",cnt[i]);
		pn();
	}

//si(X);
return 0;
}