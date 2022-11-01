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
PII a[512];
set<PII> b;
int res[512];

int dist(int i, int j)
{
	return abs(a[i].X-a[j].X)+abs(a[i].Y-a[j].Y);
}

bool solve(int sh, set<PII> b)
{
	FILL(res,-1);
	REP(ii,n/2)
	{
		int i = (ii*2+sh)%n;
		int len = dist(i,(i+1)%n)+dist(i,(i+n-1)%n);
		set<PII>::iterator it = b.lower_bound(PII(len,-1));
		if (it == b.end() || it->first != len)
			return false;
		res[i] = it->second+1;
		b.erase(it);
	}
	printf("YES\n");
	REP(i,n)
		printf(" %d"+(i==0),res[i]);
	printf("\n");
	return true;
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&m);
	REP(i,n)
	{
		scanf("%d%d",&a[i].X,&a[i].Y);
	}
	REP(i,m)
	{
		int x;
		scanf("%d",&x);
		b.insert(PII(x,i));
	}
	if (!solve(0,b) && !solve(1,b))
		printf("NO\n");
	return 0;
}