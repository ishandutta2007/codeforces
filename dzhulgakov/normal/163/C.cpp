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

#define N 111000
int n;
LL l,v1,v2,dist,wrap;
LL a[N*3];
LL res[N];

LL r64()
{
	int x;
	scanf("%d",&x);
	return x;
}

int main()
{
	//freopen("a.in","r",stdin);

	scanf("%d",&n);
	l=r64();
	v1=r64();
	v2=r64();
	dist = v2*l;
	REP(i,n)
	{
		a[i]=r64();
		a[i] *= v1+v2;
	}
	sort(a,a+n);
	wrap = 2*l*(v1+v2);
	REP(i,n)
		a[i+n] = a[i]+wrap;
	a[2*n] = 2*wrap;

	vector<LL> st;
	st.pb(0);
	REP(i,n)
		st.pb(a[i]);
	st.pb(wrap);
	REP(i,n)
	{
		LL y = a[i]-dist;
		if (y < 0) y += wrap;
		st.pb(y);
	}
	SORT(st);
	UNIQUE(st);
	CLEAR(res);
	int i1 = 0, i2 = 0;
	REP(i,SZ(st)-1)
	{
		while (i1 < 2*n && a[i1] <= st[i]) ++i1;
		while (i1 < 2*n && a[i2] <= st[i]+dist) ++i2;
		res[i2-i1] += st[i+1]-st[i];
	}
	REP(i,n+1)
	{
		printf("%.18lf\n",res[i]/(double)wrap);
	}
	return 0;
}