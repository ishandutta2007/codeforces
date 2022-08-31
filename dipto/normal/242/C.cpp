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
#define SZ 100005
#define MOD (1<<30)
#define TEST int Test;scanf("%d",&Test);while(Test--)
#define mat_mul(c,a,b,n,mod){long long temp[10][10],k;for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(k=temp[i][j]=0;k<n;k++)temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;for(int i=0;i<n;i++) for(int j=0;j<n;j++)c[i][j]=temp[i][j];}
/*********************************************************/
map< pair<int,int>, int> vis,valid;
queue< pair<pair<int,int>,int> > Q;

void solve()
{
	int x0,y0,x1,y1,n;
	cin>>x0>>y0>>x1>>y1;

	cin>>n;
	FOR(i,0,n-1)
	{
		int r,a,b;
		cin>>r>>a>>b;

		FOR(j,a,b)
			valid[mp(r,j)]=1;
	}

	Q.push(mp(mp(x0,y0),0));
	while(1)
	{
		while(!Q.empty() && vis[Q.front().first])
			Q.pop();
		if(Q.empty()) break;

		int x,y,v;
		x=Q.front().first.first;
		y=Q.front().first.second;
		v=Q.front().second;
		vis[Q.front().first]=1;
		Q.pop();
		if(x==x1 && y==y1) {cout<<v<<endl;return;}


		if(valid[mp(x+1,y)]) Q.push(mp(mp(x+1,y),v+1));
		if(valid[mp(x,y+1)]) Q.push(mp(mp(x,y+1),v+1));
		if(valid[mp(x-1,y)]) Q.push(mp(mp(x-1,y),v+1));
		if(valid[mp(x,y-1)]) Q.push(mp(mp(x,y-1),v+1));

		if(valid[mp(x+1,y+1)]) Q.push(mp(mp(x+1,y+1),v+1));
		if(valid[mp(x+1,y-1)]) Q.push(mp(mp(x+1,y-1),v+1));
		if(valid[mp(x-1,y+1)]) Q.push(mp(mp(x-1,y+1),v+1));
		if(valid[mp(x-1,y-1)]) Q.push(mp(mp(x-1,y-1),v+1));

	}

	cout<<"-1"<<endl;
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