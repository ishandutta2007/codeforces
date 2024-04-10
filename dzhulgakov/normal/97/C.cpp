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

double a[128];
double b[128];
double c[128];

typedef vector<double> VD;

namespace SimplexMethod {
const double EPS = 1.0E-12;
vector<VD> a; VD b, c, res;
VI N, kt; int m;
void pivot(int k, int s, int e) {
    int x = kt[s];
    double p = a[s][e];
    REP(i, k) a[s][i] /= p;
    b[s] /= p;
    N[e] = false;
    REP(i, m) if (i != s) {
        b[i] -= a[i][e] * b[s];
        a[i][x] = -a[i][e] * a[s][x]; }
    REP(j, k) if (N[j]) {
        c[j] -= c[e] * a[s][j];
        REP(i, m) if (i != s)
            a[i][j] -= a[i][e] * a[s][j]; }
    kt[s] = e;
    N[x] = true;
    c[x] = -c[e] * a[s][x]; }
VD doit(int k) {
    VD res;
    while (true) {
        int e = -1, s = -1;
        REP(i, k) if (N[i] && c[i] > EPS) {e = i; break; }
        if (e == -1) break;
        REP(i, m) if (a[i][e] > EPS && (s == -1 || b[i] / a[i][e] < b[s] / a[s][e])) s = i;
        if (s == -1) return VD(); // unbounded
        pivot(k, s, e); }
    res.resize(k, 0);
    REP(i, m) res[kt[i]] = b[i];
    return res; }
// max c * x, while A * x <= b, x >= 0,       .
VD simplex(vector<VD> _A, VD _b, VD _c) { a=_A; b=_b; c=_c;
    m = SZ(a);
    int n = SZ(a[0]); int k = n + m + 1;
    c.resize(n + m); kt.resize(m);
    N = VI(k, true);
    REP(i, m) {
        a[i].resize(k);
        a[i][n + i] =  1;
        a[i][k - 1] = -1;
        kt[i] = n + i;
        N[kt[i]] = false; }
    int s = min_element(ALL(b)) - b.begin();
    if (b[s] < -EPS) {
        c = VD(k, 0);
        c[k - 1] = -1;
        pivot(k, s, k - 1);
        res = doit(k);
        if (res[k - 1] > EPS) return VD(); // infeasible
        REP(i, m) if (kt[i] == k - 1) REP(j, k-1)
            if (N[j] && (a[i][j] < -EPS || EPS < a[i][j])) {
                pivot(k, i, j); break; }
        c = _c; c.resize(k, 0);
        REP(i, m) REP(j, k) if (N[j])
            c[j] -= c[kt[i]] * a[i][j]; }
    res = doit(k - 1);
    if (!res.empty()) res.resize(n);
    return res; }
}

int n;
double p[128];

int main()
{
	//freopen("c.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&n);
	REP(i,n+1) scanf("%lf",p+i);
	//n=100; REP(i,101) p[i] = 1.0/n*i;
	VD c(p,p+n+1);
	vector<VD> a(2);
	VD b(2);
	REP(i,n+1)
	{
		a[0].pb(2*i-n);
		b[0] = 0;
		a[1].pb(1.0);
		b[1] = 1.0;
	}
	/*REP(i,n+1)
	{
		a[i] = 2*i-n;
		b[i] = 1.0;
		c[i] = p[i];
	}*/
	//double res = lambda_solve(n+1,0,1.0);
	double res = 0;
	VD ans = SimplexMethod::simplex(a,b,c);
	REP(i,n+1)
		res += ans[i]*p[i];
	printf("%.12lf\n",res);
	return 0;
}