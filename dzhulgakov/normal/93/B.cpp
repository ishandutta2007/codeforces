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

int n,w,m;
vector<pair<int,double> > res[1024];

bool solve(int n, double w, int m)
{
	double s = w*n/(double)m;
	if (2*n < m) return false;
	if (m>=n)
	{
		REP(i,n)
			res[m-n+i].pb(MP(i,s));
		m-=n;
		w-=s;
	}
	int i = 0;
	double left = w;
	REP(j,m)
	{
		double fi = s;
		while (fi > 1.0e-8)
		{
			if (left < 1.0e-8)
			{
				i++;
				left = w;
				if (i == n)
					return false;
			}
			double t = min(fi,left);
			left -= t;
			fi -= t;
			res[j].pb(MP(i,t));
		}
	}
	map<int,int> q;
	REP(i,::m) REP(j,SZ(res[i]))
		q[res[i][j].first]++;
	for (map<int,int>::iterator it = q.begin(); it != q.end(); ++it)
		if (it->second > 2)
			return false;
	return true;
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&w,&m);
	if (!solve(n,w,m))
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		REP(i,m)
		{
			REP(j,SZ(res[i])) printf(" %d %.10lf"+(j==0),res[i][j].X+1,res[i][j].Y);
			printf("\n");
		}
	}
	return 0;}