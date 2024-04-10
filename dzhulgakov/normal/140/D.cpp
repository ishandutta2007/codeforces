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

#define K 800
int n;
int a[128];
PII d[K+10];

int main()
{
	scanf("%d",&n);
	REP(i,n) scanf("%d",a+i);
	sort(a,a+n);
	CLEAR(d);
	REP(i,n) for (int x = K; x >= 10+a[i]; --x)
	{
		PII nw = d[x-a[i]];
		nw.first++;
		nw.second+=max(0,x-6*60);
		if (d[x].first < nw.first || d[x].first == nw.first && d[x].second > nw.second)
			d[x] = nw;
	}
	PII res(0,0);
	for (int x = 10; x <= 720; ++x)
	{
		PII nw = d[x];
		if (res.first < nw.first || res.first == nw.first && res.second > nw.second)
			res = nw;
	}
	printf("%d %d\n",res.X,res.Y);
	return 0;
}