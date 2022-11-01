#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 1024

int nn,mm,k;
PII a[N];
int cid[N];
pair<int,PII> b[N];

LL sqr(LL x) {return x*x;}

bool inside(PII p, pair<int,PII> c)
{
	return (sqr(p.X - c.second.X) < sqr(c.first)-sqr(p.Y - c.second.Y));
}

bool inside(pair<int,PII> ci, pair<int,PII> c)
{
	return ci.first < c.first && (sqr(ci.second.X - c.second.X) < sqr(c.first-ci.first)-sqr(ci.second.Y - c.second.Y));
}

VI adj[N]; vector<pair<int,int*> > q[N]; int p[N], anc[N], h[N]; bool u[N];
int getset (int v) { return v==p[v]?v:p[v]=getset(p[v]); }
void unionset (int a, int b, int new_anc) {a=getset(a), b=getset(b);
	if (rand() & 1)  swap (a, b); p[a]=b, anc[b]=new_anc; }
void dfs (int v) {
	p[v] = v, anc[v] = v; u[v] = true;
	REP(i,SZ(adj[v])) if (!u[adj[v][i]]) {h[adj[v][i]]=h[v]+1; dfs(adj[v][i]); unionset(v,adj[v][i],v); }
	REP(i,SZ(q[v])) if (u[q[v][i].first]) *q[v][i].Y=anc[getset(q[v][i].X)]; }

PII quer[111000];
int lca[111000];

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d%d",&nn,&mm,&k);
	REP(i,nn)
		scanf("%d%d",&a[i].X,&a[i].Y);
	REP(i,mm)
		scanf("%d%d%d",&b[i].X,&b[i].Y.X,&b[i].Y.Y);
	sort(b,b+mm);
	REP(i,nn)
	{
		for (cid[i]=0; cid[i]<mm && !inside(a[i], b[cid[i]]); cid[i]++) ;
	}
	REP(i,mm)
	{
		int ins = mm;
		REP(j,mm) if (j > i && inside(b[i], b[j]))
		{
			ins = j;
			break;
		}
		adj[ins].pb(i);
	}
	CLEAR(u);
	CLEAR(h);
	REP(step,k)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		x=cid[x];
		y=cid[y];
		quer[step] = PII(x,y);
		q[x].pb(make_pair(y,&lca[step]));
		q[y].pb(make_pair(x,&lca[step]));
	}
	dfs(mm);
	REP(step,k)
	{
		int x = quer[step].X;
		int y = quer[step].Y;
		printf("%d\n", h[x]+h[y]-2*h[lca[step]]);
	}
	return 0;
}