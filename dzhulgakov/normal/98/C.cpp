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
#define eps 1.0e-9
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

template<class T> inline T gcd(T a,T b) {
	if(a<0)a=-a; if(b<0)b=-b; if(a<b)swap(a,b);
	while (b) {T t = b; b=a%b; a=t;} return a; }

double a,b,l;

double f(double x)
{
	return a*sin(x) + b*cos(x) - l*cos(x)*sin(x);
}

double res;
#define STEP 1.0e-4

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lf%lf%lf",&a,&b,&l);
	res = l;
	for (double s = 0; s < pi/2; s+=STEP)
	{
		double e = min(s+STEP,pi/2);
		double l = s;
		double r = e;
		res = min(res,min(f(l),f(r)));
		REP(step,90)
		{
			double m1 = (l*2+r)/3;
			double m2 = (l+r*2)/3;
			if (l==m1 || m1 == m2 || m2 == r) break;
			double q1 = f(m1);
			double q2 = f(m2);
			res = min(res,min(q1,q2));
			if (q1 < q2) r = m2;
			else l = m1;
		}
	}
	if (a>b) swap(a,b);
	if (l < a+eps) res = l;
	else if (l<b+eps)
		res = max(res,min(a,l));
	if (res > 0)
		printf("%.12lf\n",res);
	else
		printf("My poor head =(\n");
}