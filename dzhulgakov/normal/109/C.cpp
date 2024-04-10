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

#define N 111000
int n;
VPII e1,e2;
VI a[N];
int gr[N],grk,grs[N];

void dfs1(int v, int p = -1)
{
	grs[grk]++;
	gr[v] = grk;
	REP(i,SZ(a[v]))
	{
		int ver = a[v][i];
		if (ver == p) continue;
		if (gr[ver]==-1)
			dfs1(ver,v);
	}
}

int main()
{
	//freopen("c.in","r",stdin);
	//freopen(".out","w",stdout);

	VI d;
	FOR(len,1,9) REP(mask,1<<len)
	{
		int x = 0;
		REP(i,len)
			x = x*10 + (mask&(1<<i) ? 4 : 7);
		d.pb(x);
	}
	SORT(d);

	scanf("%d",&n);
	REP(i,n-1)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		--x;--y;
		if (binary_search(ALL(d),w))
			e2.pb(PII(x,y));
		else
		{
			e1.pb(PII(x,y));
			a[x].pb(y);
			a[y].pb(x);
		}
	}
	FILL(gr,-1);
	CLEAR(grs);
	grk=0;
	REP(i,n)
		if (gr[i]==-1)
		{
			dfs1(i);
			grk++;
		}
	LL res = 0;
	REP(i,grk)
		res += grs[i]*(LL)((n-grs[i])*(LL)(n-grs[i]-1));
	cout << res << endl;
	/*REP(i,n) a[i].clear();
	REP(i,n-1)
	{
		int x = gr[e2[i].X];
		int y = gr[e2[i].Y];
		
	}*/
	return 0;
}