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

VVI res;
priority_queue<PII> q;
map<int,int> a;

int main()
{
	int n;
	scanf("%d",&n);
	REP(i,n)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for (map<int,int>::iterator it = a.begin(); it != a.end(); ++it)
	{
		q.push(PII(it->second,it->first));
	}
	while (q.size() >= 3)
	{
		PII p1 = q.top(); q.pop();
		PII p2 = q.top(); q.pop();
		PII p3 = q.top(); q.pop();
		VI r;
		r.pb(p1.second);
		r.pb(p2.second);
		r.pb(p3.second);
		p1.first--;
		p2.first--;
		p3.first--;
		if (p1.first > 0) q.push(p1);
		if (p2.first > 0) q.push(p2);
		if (p3.first > 0) q.push(p3);
		SORT(r);
		reverse(ALL(r));
		res.pb(r);
	}
	printf("%d\n",SZ(res));
	REP(i,SZ(res))
	{
		REP(j,SZ(res[i])) printf(" %d"+(j==0),res[i][j]);
		printf("\n");
	}
	return 0;
}