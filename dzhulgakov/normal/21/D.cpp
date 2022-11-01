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
#define INF 1000000000
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

#define N 16
int n,m;
int deg[N];
int a[N][N],d[N][N];
bool mark[N];
int mem[1<<15];

void dfs(int v)
{
	if (mark[v]) return;
	mark[v]=true;
	REP(i,n) if (a[v][i] < INF)
		dfs(i);
}

int rec(int mask)
{
	int &res = mem[mask];
	if (res!=-1) return res;
	if (mask == 0) return res=0;
	res = INF;
	int i1;
	for (i1=0; (mask&(1<<i1))==0; i1++);
	FOR(i2,i1+1,n-1) if (mask&(1<<i2))
		res = min(res, d[i1][i2]+rec(mask^(1<<i1)^(1<<i2)));
	return res;
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n)
		a[i][j]=INF;
	int sum=0;
	REP(i,m)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		x--;y--;
		a[x][y]=min(a[x][y],c);
		a[y][x]=min(a[y][x],c);
		sum+=c;
		deg[x]++,deg[y]++;
	}
	CLEAR(mark);
	dfs(0);
	bool bad = false;
	REP(i,n) if (!mark[i]&&deg[i]>0)
		bad=true;
	if (bad)
	{
		printf("-1\n");
		return 0;
	}
	memcpy(d,a,sizeof a);
	REP(i,n) REP(j,n) REP(k,n)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	FILL(mem,-1);
	int mask = 0;
	REP(i,n) if (deg[i]%2 == 1)
		mask |= 1<<i;
	int res = sum+rec(mask);
	printf("%d\n",res);
	return 0;
}