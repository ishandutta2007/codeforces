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

int n,m;
int d[45][1<<6][1<<6];

template<class T> inline int bitcnt(T n){ int res=0;
	for (; n!=0; n&=n-1) res++; return res; }

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	if (n<m) swap(n,m);
	FILL(d,63);
	d[0][0][0] = 0;
	int full = (1<<m)-1;
	REP(s,n)
	{
		REP(m1,1<<m) REP(m2,1<<m)
		{
			REP(j,m)
			{
				int t1 = m1 | (1<<j);
				int t2 = m2 | (1<<j);
				if (j > 0) t1 |= (1<<(j-1));
				if (j < m-1) t1 |= (1<<(j+1));
				d[s][t1][t2] = min(d[s][t1][t2], d[s][m1][m2]+1);
			}
		}
		REP(m1,1<<m) REP(m2,1<<m)
		{
			int need = full - m1;
			int &q = d[s+1][(m2 | need | (need >> 1) | (need << 1))&full][need];
			q = min(q,d[s][m1][m2]+bitcnt(need));
		}
	}
	int res = INF;
	REP(m2,1<<m)
		res = min(res,d[n-1][full][m2]);
	if (n>1)
		res = min(res,d[n-2][full][full]);
	printf("%d\n",n*m-res);
	return 0;
}