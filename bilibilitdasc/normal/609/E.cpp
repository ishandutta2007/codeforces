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
const int N=200005;
const int X=20;
int n,m,cnt;
ll cst;
struct edge{
	int u,v;
	ll w;
	int id;
};
bool operator<(const edge&a,const edge&b)
{
	return a.w<b.w;
}
vector<pair<int,ll> > mst[N];
edge e[N];
int p[N];
int getp(int x)
{
	if(p[x]==x) return x;return p[x]=getp(p[x]);
}
void mer(int x,int y)
{
	p[getp(x)]=getp(y);
}
bool sam(int x,int y)
{
	return getp(x)==getp(y);
}
void calc_mst()
{
	rep1(i,n) p[i]=i;cnt=0;
	sort(e+1,e+1+m);
	int ind=0;
	while(cnt<n-1)
	{
		++ind;
		if(!sam(e[ind].u,e[ind].v))
		{
			mer(e[ind].u,e[ind].v);
			mst[e[ind].u].pb(mp(e[ind].v,e[ind].w));
			mst[e[ind].v].pb(mp(e[ind].u,e[ind].w));
			++cnt;
			cst+=e[ind].w;
		}
	}
	//rep1(i,n)
	//{
	//	rep(j,mst[i].size())
	//	{
	//		cout<<i<<"-"<<mst[i][j].fi<<endl;
	//	}
	//}
}
int par[X][N];
ll Mx[X][N];
int dep[N];
void dfs(int x,int d,int p)
{
	par[0][x]=p;
	dep[x]=d;
	rep(i,mst[x].size())
	{
		int u=mst[x][i].fi;
		if(u!=p) dfs(u,d+1,x);
		else Mx[0][x]=mst[x][i].se;
	}
}
void init()
{
	dfs(1,0,0);
	for(int i=1;i<X;++i)
	for(int j=1;j<=n;++j)
	{
		par[i][j]=par[i-1][par[i-1][j]];
		Mx[i][j]=max(Mx[i-1][j],Mx[i-1][par[i-1][j]]);
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
ll tmp(int x,int lc)
{
	int dif=dep[x]-dep[lc];
	ll mx=0;
	for(int i=0;i<X;++i)
	{
		if((dif>>i)&1)
		{
			mx=max(mx,Mx[i][x]);
			x=par[i][x];
		}
	}
	return mx;
}
ll Ans(int x,int y,ll w)
{
	int lc=lca(x,y);
	return cst+w-max(tmp(x,lc),tmp(y,lc));
}
ll ans[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep1(i,m)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].id=i;
	}
	calc_mst();init();
	//cout<<"QWQ"<<endl;
	rep1(i,m)
	{
		ans[e[i].id]=Ans(e[i].u,e[i].v,e[i].w);
	}
	rep1(i,m)
	{
		cout<<ans[i]<<endl;
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