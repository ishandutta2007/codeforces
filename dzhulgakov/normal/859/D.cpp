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
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <stack>

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
//const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 100
int k,n,a[N][N];
double d[10][N],e[10][N];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&k);
	n = 1<<k;
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]);

	REP(i,n) d[0][i] = 1.0;
	FOR(level,1,k) {
		double sum = 0;
		REP(i,n)
		{
			d[level][i] = 0;
			int base = ((i >> (level-1)) ^ 1) << (level-1);
			REP(sh,(1<<(level-1)))
			{
				int j = base+sh;
				d[level][i] += (a[i][j]/100.0)*d[level-1][j];
			}
			d[level][i] *= d[level-1][i];
			sum += d[level][i];
		}
		//fprintf(stderr,"%.12lf\n",sum);
	}
	CLEAR(e);
	FOR(level,1,k) {
		REP(i,n)
		{
			e[level][i] = 0;
			int base = ((i >> (level-1)) ^ 1) << (level-1);
			REP(sh,(1<<(level-1)))
			{
				int j = base+sh;
				e[level][i] = max(e[level][i], e[level-1][i] + e[level-1][j] + (1<<(level-1))*d[level][i]);
			}
		}
	}

	double res = 0;
	REP(i,n) res = max(res,e[k][i]);
	printf("%.18lf\n",res);
	return 0;
}