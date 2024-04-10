#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
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

double a,v,l,d,w;

double trap(double dist, double v0)
{
	double acctime = (v-v0)/a;
	double accdist = v0*acctime + a*acctime*acctime/2.0;
	if (accdist >= dist)
	{
		double tm = (-v0+sqrt(v0*v0+2*a*dist))/a;
		return tm;
	}
	return acctime + (dist-accdist)/v;
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
	double speedat = min(min(w,v),sqrt(2.0*a*d));
	double res = 0;
	// accelerate
	double dist = d;
	res += speedat/a;
	dist -= speedat*speedat/a/2.0;
	res += 2*trap(dist/2,speedat);
	res += trap(l-d,speedat);
	printf("%.10lf\n",res);
	return 0;
}