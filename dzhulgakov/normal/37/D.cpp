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

int cnk[1024][1024];
int d[128][1024];
int x[1024],y[1024];
int n;

#define MOD 1000000007

int main()
{
	//freopen("data.in","r",stdin);

	CLEAR(cnk);
	cnk[0][0]=1;
	REP(i,1024) if (i>0) REP(j,1024)
	{
		cnk[i][j] = cnk[i-1][j];
		if (j>0)
			cnk[i][j] = (cnk[i][j] + cnk[i-1][j-1]) % MOD;
	}
	scanf("%d",&n);
	REP(i,n) scanf("%d",x+i);
	REP(i,n) scanf("%d",y+i);
	CLEAR(d);
	REP(i,y[n-1]+1)
		d[n-1][i] = 1;
	REPD(i,n-1) REP(k,1024) FOR(take,0,min(y[i],k))
	{
		d[i][k] = (d[i][k] + cnk[k][take]*(LL)d[i+1][x[i+1]+k-take]) % MOD;
	}
	LL res = d[0][x[0]];
	int sum = 0;
	REP(i,n)
	{
		sum += x[i];
		res = (res*(LL)cnk[sum][x[i]])%MOD;
	}
	printf("%d\n",res);
	return 0;
}