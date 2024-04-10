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

#define N 4111
int n,k;
int fn[N][N];

int main()
{
	//freopen("d.in","r",stdin);
	scanf("%d%d",&n,&k);
	CLEAR(fn);
	int res = 0;
	//if (n==k) res = 86400;
	REP(use,k+1) fn[0][use]=1;
	REP(i,n)
	{
		int t,d;
		scanf("%d%d",&t,&d);
		REP(use,k+1)
			fn[i+1][use] = INF;
		REP(use,k+1)
		{
			res = max(res,t-fn[i][use]);
			fn[i+1][use] = min(fn[i+1][use], max(fn[i][use],t)+d);
			if (use<k)
				fn[i+1][use+1] = min(fn[i+1][use+1], fn[i][use]);
		}
	}
	REP(use,k+1) res = max(res, 86400+1-fn[n][use]);
	printf("%d\n",res);
	return 0;
}