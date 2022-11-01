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

int n4,n7,n47,n74;

bool solve()
{
	if (abs(n47-n74)>1) return false;
	REP(fst,10) if (fst==4||fst==7)
	{
		if (fst==4 && n47 < n74) continue;
		if (fst==7 && n47 > n74) continue;
		int mn4 = (fst==4 ? 1 : 0) + n74;
		int mn7 = (fst==7 ? 1 : 0) + n47;
		if (mn4 > n4 || mn7 > n7) continue;
		VI order;
		int groups = n47+n74+1;
		int e4 = n4-mn4;
		int e7 = n7-mn7;
		REP(i,groups)
		{
			int cur = ((fst==4) ^ (i%2 == 0) ^ 1) ? 4 : 7;
			printf("%d",cur);
			if (i<=1 && cur == 4)
				REP(i,e4) printf("4");
			if (i>=groups-2 && cur==7)
				REP(i,e7) printf("7");
		}
		printf("\n");
		return true;
	}
	return false;
}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d%d",&n4,&n7,&n47,&n74);
	if (!solve())
		printf("-1\n");
	return 0;
}