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
#define RND ((x*a+b)%c)
#define TEST int Test;scanf("%d",&Test);while(Test--)
#define mat_mul(c,a,b,n,mod){long long temp[10][10],k;for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(k=temp[i][j]=0;k<n;k++)temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;for(int i=0;i<n;i++) for(int j=0;j<n;j++)c[i][j]=temp[i][j];}
/*********************************************************/
vector< pair<int,string> > t,buc[5];
int x,a,b,c;

int rnd()
{
	return x=RND;
}

void solve()
{
	int n;
	scanf("%d %d %d %d %d",&n,&x,&a,&b,&c);

	FOR(i,0,n-1)
	{
		string s;
		int r;
		cin>>s>>r;
		t.pb(mp(-r,s));
	}

	sort(t.begin(),t.end());

	FOR(i,0,n/4-1)
		{
			buc[1].pb(t[i]);
			buc[2].pb(t[i+n/4]);
			buc[3].pb(t[i+2*n/4]);
			buc[4].pb(t[i+3*n/4]);
	}

	int m=n/4,s=n/4;
	FOR(i,0,m-1)
	{
		printf("Group %c:\n",'A'+i);
		int ind=rnd()%s;
		cout<<buc[1][ind].second<<endl;
		remove(buc[1].begin(),buc[1].end(),buc[1][ind]);
		ind=rnd()%s;
		cout<<buc[2][ind].second<<endl;
		remove(buc[2].begin(),buc[2].end(),buc[2][ind]);
		ind=rnd()%s;
		cout<<buc[3][ind].second<<endl;
		remove(buc[3].begin(),buc[3].end(),buc[3][ind]);
		ind=rnd()%s;
		cout<<buc[4][ind].second<<endl;		
		remove(buc[4].begin(),buc[4].end(),buc[4][ind]);
		s--;
	}
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