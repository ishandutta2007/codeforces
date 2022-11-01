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
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <stack>

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
//const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 128
double a[N][N];

vector<double> gen(double x, double r)
{
	vector<double> res;
	res.push_back(x+r);
	res.push_back(x-r);
	if (x-r <= 0 && x+r >= 0)
		res.push_back(0);
	return res;
}

void combine(double x, double y, double r, double& rlow, double& rhigh) {
	vector<double> q1 = gen(x,r);
	vector<double> q2 = gen(y,r);
	double mn = 1e50, mx=-1e50;
	REP(i,SZ(q1)) REP(j,SZ(q2))
	{
		double t= q1[i]*q2[j];
		mn=min(mn,t);
		mx=max(mx,t);
	}
	rlow = max(rlow,mn);
	rhigh = min(rhigh,mx);
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);

	REP(i,2)REP(j,2) scanf("%lf",&a[i][j]);
	double left = 0, right = 1e15;
	REP(step,200) {
		double mid = (left+right)/2;
		double rlow = -1e50, rhigh=+1e50;
		combine(a[0][0],a[1][1],mid,rlow,rhigh);
		combine(a[0][1],a[1][0],mid,rlow,rhigh);
		if (rlow <= rhigh)
			right = mid;
		else
			left = mid;
	}
	printf("%.12lf\n",left);
	return 0;
}