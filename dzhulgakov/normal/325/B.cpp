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

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	LL n;
	cin >> n;
	vector<LL> res;
	for (int i = 0; i < 61; i++)
	{
		LL A = 2;
		LL B = 1 + 2*((1LL << i) - 1);
		LL C = (1LL << i) - 1;
		LL left = 0;
		LL right = sqrt((double)n)*2 + 100;
		while (left <= right)
		{
			LL k = (left+right) / 2;
			double dval = A*(double)k*(double)k + B*(double)k + C;
			if (dval > n*1.1)
			{
				right = k-1;
				continue;
			}
			LL val = A*k*k + B*k + C;
			if (val == n)
			{
				res.pb((2*k+1)<<i);
				break;
			}
			if (val > n)
				right = k - 1;
			else
				left = k + 1;
		}
	}
	UNIQUE(res);
	REP(i,SZ(res))
	{
		cout << res[i] << "\n";
	}
	if (res.empty()) cout << "-1\n";
	return 0;
}