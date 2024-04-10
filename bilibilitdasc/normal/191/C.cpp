#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=100005;
const int X=20;
int n,q,U,V;
int u1[N];
int v1[N];
int par[X][N];
int dep[N];
int num[N];
int Num[N];
vector<int> con[N];
void dfs(int x,int d,int p)
{
	par[0][x]=p;
	dep[x]=d;
	rep(i,con[x].size())
	{
		int u=con[x][i];
		if(u!=p) dfs(u,d+1,x);
	}
}
void init()
{
	dfs(1,0,0);
	for(int i=1;i<X;++i)
	for(int j=1;j<=n;++j)
	{
		par[i][j]=par[i-1][par[i-1][j]];
	}
	for(int i=1;i<n;++i)
	{
		if(dep[u1[i]]<dep[v1[i]])
		{
			swap(u1[i],v1[i]);
		}
	}
}
int lca(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	int dif=dep[y]-dep[x];
	for(int i=0;i<X;++i)
	{
		if((dif>>i)&1)
		{
			y=par[i][y];
		}
	}
	if(x==y) return x;
	for(int i=X-1;i>=0;--i)
	{
		if(par[i][x]!=par[i][y])
		{
			x=par[i][x];
			y=par[i][y];
		}
	}
	return par[0][x];
}
void calc_ans(int x,int y)
{
	++num[x];
	++num[y];
	----num[lca(x,y)];
}
void aftermath(int v)
{
	Num[v]=num[v];
	rep(i,con[v].size())
	{
		int u=con[v][i];
		if(u!=par[0][v])
		{
			aftermath(u);
			Num[v]+=Num[u];
		}
	}
}
int answer(int i)
{
	return Num[u1[i]];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&u1[i],&v1[i]);
		con[u1[i]].pb(v1[i]);
		con[v1[i]].pb(u1[i]);
	}
	init();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&U,&V);
		calc_ans(U,V);
	}
	aftermath(1);
	for(int i=1;i<n;++i)
	{
		printf("%d",answer(i));
		if(i==n-1) printf("\n");
		else printf(" ");
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/