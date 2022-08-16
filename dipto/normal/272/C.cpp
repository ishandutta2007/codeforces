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
LL tree[1000000];
int flag[1000000];;

void update(int l,int x,int y,int r,LL v,int n)
{
	if(l==x && r==y) {tree[n]=v;flag[n]=1;return;}

	if(flag[n]==1)
	{
		tree[2*n]=tree[2*n+1]=tree[n];
		flag[2*n]=flag[2*n+1]=1;
		flag[n]=0;
	}

	int m=(r+l)/2;
	if(x>m) update(m+1,x,y,r,v,2*n+1);
	else if(y<=m) update(l,x,y,m,v,2*n);
	else
	{
		update(m+1,m+1,y,r,v,2*n+1);
		update(l,x,m,m,v,2*n);
	}

	tree[n]=max(tree[2*n],tree[2*n+1]);
	
	
}

LL query(int l,int x,int y,int r,int n)
{
	if(l==x && r==y) {return tree[n];}
	if(flag[n]==1) return tree[n];
	int m=(r+l)/2;
	LL a=0,b=0;
	if(x>m) a=query(m+1,x,y,r,2*n+1);
	else if(y<=m) b=query(l,x,y,m,2*n);
	else
	{
		a=query(m+1,m+1,y,r,2*n+1);
		b=query(l,x,m,m,2*n);
	}

	return max(a,b);
}

void solve()
{
	int n;
	cin>>n;
	FOR(i,1,n)
	{
		LL t;
		cin>>t;
		update(1,i,i,n,t,1);
	}
	int m;
	cin>>m;
	FOR(i,1,m)
	{
		LL w,h;
		cin>>w>>h;
		LL v=query(1,1,(int)w,n,1);
		cout<<v<<endl;
		update(1,1,(int)w,n,v+h,1);
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