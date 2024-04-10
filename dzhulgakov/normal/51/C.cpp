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

#define N 222000
int a[N];

int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	REP(i,n) scanf("%d",a+i);
	sort(a,a+n);
	LL left = 0, right = 2*(a[n-1]-a[0]);
	while (left < right)
	{
		LL d = (left+right)/2;
		int p = 0;
		REP(step,3)
		{
			if (p == n) break;
			LL w = min((LL)a[n-1], a[p]+d) + 1;
			p = lower_bound(a,a+n,w)-a;
		}
		if (p==n)
			right = d;
		else
			left = d+1;
	}
	printf("%.6lf\n", 0.5*left);
	int p = 0;
	REP(step,3)
	{
		if (p == n) { printf(" %.6lf"+(step==0), a[n-1]*1.0);  continue; }
		printf(" %.6lf"+(step==0), a[p]+left*0.5);
		LL w = min((LL)a[n-1], a[p]+left) + 1;
		p = lower_bound(a,a+n,w)-a;
	}
	printf("\n");
	return 0;
}