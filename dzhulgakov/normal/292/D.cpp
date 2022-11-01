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

#define N 512
#define M 11000
int fr[M][N];
int bc[M][N];
int n,m;
PII edge[M];

int g[N][N*2],k[N];
bool mark[N];

int p[N],r[N];
void initset() { REP(i,n) p[i]=i,r[i]=0; }
int getset(int v) {	return p[v]==v ? v : (p[v]=getset(p[v])); }
void mergeset(int v, int u) { if (r[v]<r[u]) p[v]=u; else {p[u]=v; r[v]+=r[u]==r[v]; } }

void add(int v, int u)
{
	g[v][k[v]++]=u;
	g[u][k[u]++]=v;
}

void dfs(int v)
{
	mark[v]=true;
	REP(i,k[v])
	{
		int vv = g[v][i];
		if (!mark[vv])
			dfs(vv);
	}
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&m);
	REP(i,m)
	{
		scanf("%d%d",&edge[i].X,&edge[i].Y);
		--edge[i].X;--edge[i].Y;
	}
	initset();
	REP(i,m)
	{
		REP(j,n)
			fr[i][j] = getset(j);
		int x = getset(edge[i].X);
		int y = getset(edge[i].Y);
		mergeset(x,y);
	}
	initset();
	REPD(i,m)
	{
		REP(j,n)
			bc[i][j] = getset(j);
		int x = getset(edge[i].X);
		int y = getset(edge[i].Y);
		mergeset(x,y);
	}
	int kk;
	scanf("%d",&kk);
	REP(step,kk)
	{
		int left,right;
		scanf("%d%d",&left,&right);
		--left;--right;
		CLEAR(k);
		REP(i,n)
		{
			if (fr[left][i] != i)
				add(fr[left][i],i);
			if (bc[right][i] != i)
				add(bc[right][i],i);
		}
		CLEAR(mark);
		int res = 0;
		REP(i,n) if (!mark[i])
		{
			 dfs(i);
			++res;
		}
		printf("%d\n",res);
	}
	return 0;
}