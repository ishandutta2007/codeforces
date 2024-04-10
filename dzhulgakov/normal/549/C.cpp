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

#define N 222000
int n,k;

int k0=0,k1=0;

int solve() {
	for (int who = 0; k0+k1 > k; who = 1-who)
	{
		if (k0 == 0)
		{
			k1--;
			continue;
		}
		if (k1 == 0)
		{
			k0--;
			continue;
		}
		if (k0+k1-k == 1)
			return who;
		if (who == 0)
			--k0;
		else
			--k1;
	}
	return k1%2 == 1 ? 0 : 1;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&k);
	REP(i,n) {
		int x;
		scanf("%d",&x);
		if (x%2) ++k1;
		else ++k0;
	}
	printf("%s\n", solve() == 0? "Stannis" : "Daenerys");
	return 0;
}