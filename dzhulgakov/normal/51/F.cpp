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

#define N 2222
int n,m;
VI a[N],b[N];
int mark[N],tmm[N],tick;
int nn,gid[N];
VI stack;

int dfs1(int v, int parent)
{
	int res = tmm[v] = tick++;
	mark[v] = 1;
	stack.pb(v);
	REP(i,SZ(a[v]))
	{
		int ver = a[v][i];
		if (ver == parent) continue;
		if (mark[ver])
			res = min(res, tmm[ver]);
		else
			res = min(res, dfs1(ver,v));
	}
	mark[v] = 2;
	if (res == tmm[v])
	{
		gid[v] = nn;
		while (stack.back() != v)
		{
			gid[stack.back()] = nn;
			stack.pop_back();
		}
		stack.pop_back();
		nn++;
	}
	return res;
}

int glmax,total;

PII dfs2(int v, int parent)
{
	mark[v]=1;
	VI q;
	int res = 0;
	int leaves = 0;
	REP(i,SZ(b[v]))
	{
		int ver = b[v][i];
		if (ver == parent) continue;
		PII x = dfs2(ver,v);
		leaves += x.second;
		q.pb(x.first-x.second);
	}
	if (q.empty())
		leaves++;
	REP(i,SZ(q))
		res = max(res, q[i]+leaves+1);
	res = max(res, leaves);
	SORT(q);
	if (SZ(q) >= 2)
	{
		glmax = max(glmax, q[SZ(q)-1]+q[SZ(q)-2]+1-(parent==-1&&SZ(b[v])==1));
	}
	glmax = max(glmax,res-leaves-(parent==-1&&SZ(b[v])==1));
	if (parent==-1&&SZ(b[v])==1) leaves++;
	return PII(res,leaves);
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d",&n,&m);
	REP(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	CLEAR(mark);
	FILL(gid,-1);
	tick = 0;
	nn = 0;
	REP(i,n) if (mark[i]==0)
	{
		stack.clear();
		dfs1(i,-1);
	}
	int res = 0;
	REP(i,n) REP(j,SZ(a[i]))
		if (gid[a[i][j]] != gid[i])
			b[gid[i]].pb(gid[a[i][j]]);
	CLEAR(mark);
	bool fst = true;
	REP(i,nn) if (mark[i] == 0)
	{
		if (b[i].empty())
			res++;
		else
		{
			glmax = 0;
			int leaves = dfs2(i,-1).second;
			res += glmax+leaves;
		}
		if (fst)
			fst = false;
		else
			res--;
	}
	res = n - res;
	printf("%d\n",res);
	return 0;
}