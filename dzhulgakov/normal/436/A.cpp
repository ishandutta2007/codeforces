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
#define INF 1000000000
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

#define N 2048
int n,st;
int t[N],h[N],m[N];
bool eat[N];

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&st);
	REP(i,n)
	{
		scanf("%d%d%d",t+i,h+i,m+i);
	}
	int best = 0;
	REP(iter,2)
	{
		CLEAR(eat);
		int type = iter;
		int cur = 0;
		int x = st;
		while (true)
		{
			int bb = -1;
			REP(i,n)
				if (t[i] == type && !eat[i] && h[i]<=x && (bb==-1 || m[i] > m[bb]))
					bb=i;
			if (bb == -1) break;
			++cur;
			eat[bb]=true;
			x+=m[bb];
			type^=1;
		}
		best = max(best, cur);
	}
	printf("%d\n",best);
	return 0;
}