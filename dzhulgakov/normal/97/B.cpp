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

#define N 11000
int n;
PII a[N];
set<PII> res;

void rec(int s, int e)
{
	if (s >= e) return;
	int mid = (s+e)/2;
	int m1 = mid;
	int m2 = mid;
	while (m1 > s && a[m1-1].X == a[mid].X) m1--;
	while (m2 < e && a[m2].X == a[mid].X) m2++;
	FOR(i,s,e-1) res.insert(PII(a[mid].X,a[i].Y));
	rec(s,m1);
	rec(m2,e);
}

int main()
{
	//freopen("b.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&n);
	REP(i,n)
	{
		scanf("%d%d",&a[i].X,&a[i].Y);
		res.insert(a[i]);
	}
	//n=10000;
	//REP(i,n) a[i]=PII(i,i);
	sort(a,a+n);
	rec(0,n);
	printf("%d\n",SZ(res));
	for (set<PII>::iterator it = res.begin(); it != res.end(); it++)
		printf("%d %d\n",it->first, it->second);
	return 0;
}