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

vector<LL> a;

int main()
{
	FOR(len,1,10) REP(mask,1<<len)
	{
		LL x = 0;
		REPD(i,len)
			x = x*10 + ((mask&(1<<i))?7:4);
		a.pb(x);
	}
	SORT(a);

	int n,k;
	cin >> n >> k;
	int suflen = min(n,13);
	LL suffact = 1;
	FOR(i,1,suflen) suffact*=i;
	if (k > suffact)
	{
		printf("-1\n");
		return 0;
	}
	VI left;
	REP(i,suflen) left.pb(i);
	--k;
	LL fact = suffact;
	int res = upper_bound(ALL(a),n-suflen)-a.begin();
	REP(i,suflen)
	{
		fact /= (suflen-i);
		int ord = k/fact;
		k -= fact*ord;
		int val = left[ord];
		if (binary_search(ALL(a),n-suflen+i+1) && binary_search(ALL(a),n-suflen+val+1))
			++res;
		left.erase(left.begin()+ord);
	}
	printf("%d\n",res);
	return 0;
}