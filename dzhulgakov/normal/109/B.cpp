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

int a1,a2,b1,b2,k;

LL inter(int a, int b, int c, int d)
{
	return max(0,min(b,d)-max(a,c)+1);
}

int main()
{
	//freopen("b.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d%d%d",&a1,&a2,&b1,&b2,&k);
	VI d;
	FOR(len,1,9) REP(mask,1<<len)
	{
		int x = 0;
		REP(i,len)
			x = x*10 + (mask&(1<<i) ? 4 : 7);
		d.pb(x);
	}
	d.pb(0);
	d.pb(1000111000);
	SORT(d);
	LL res = 0;
	REP(i,SZ(d)) if (i>0)
	{
		if (i + k-1 >= SZ(d)-1) continue;
		res += inter(d[i-1]+1, d[i], a1, a2)*inter(d[i+k-1],d[i+k]-1, b1, b2);
		res += inter(d[i-1]+1, d[i], b1, b2)*inter(d[i+k-1],d[i+k]-1, a1, a2);
		if (k==1 && a1 <= d[i] && d[i] <= a2 && b1 <= d[i] && d[i] <= b2)
			--res;
	}

	printf("%.12lf\n",res/(double)(a2-a1+1)/(double)(b2-b1+1));
	return 0;
}