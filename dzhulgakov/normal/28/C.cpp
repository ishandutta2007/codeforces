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
int a[64];
double d[52][52][52];
double cnk[52][52];

int main()
{
	//freopen("data.in","r",stdin);

	CLEAR(cnk);
	cnk[0][0]=1;
	REP(i,52) if (i>0) REP(j,52)
		if (j==0) cnk[i][0]=1;
		else cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];

	scanf("%d%d",&n,&m);
	REP(i,m)
	{
		scanf("%d",a+i);
	}
	CLEAR(d);
	d[0][0][0]=1;
	REP(i,m) FOR(here,0,n)
	{
		int que = (here + a[i] - 1) / a[i];
		FOR(was,0,n-here) FOR(mxq,0,n)
			d[i+1][was+here][max(mxq,que)] += d[i][was][mxq]*cnk[was+here][here];
	}
	double denom = 1;
	REP(i,n) denom*=m;
	double res = 0;
	FOR(mxq,0,n)
		res += mxq * d[m][n][mxq];
	res /= denom;
	printf("%.15lf\n",res);
	return 0;
}