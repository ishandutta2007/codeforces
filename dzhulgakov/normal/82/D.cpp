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

#define N 1024
int n;
int a[N];
int d[N][N];
PII prev[N][N];
PII st[N][N];

void check(int i, int j, int ii, int jj, int x1, int x2)
{
	if (d[ii][jj] + max(a[x1],a[x2]) < d[i][j])
	{
		d[i][j] = d[ii][jj] + max(a[x1],a[x2]);
		prev[i][j] = PII(ii,jj);
		st[i][j] = PII(x1,x2);
	}
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	REP(i,n) scanf("%d",a+i);
	CLEAR(d);
	REP(i,n) d[i][n] = a[i];
	REPD(i,n) REPD(j,n) if (i<j)
	{
		d[i][j]=INF;
		check(i,j, j+1,j+2, i,j);
		if (j+1 < n) {
			check(i,j, j,j+2, i,j+1);
			check(i,j, i,j+2, j,j+1);
		}
	}
	printf("%d\n",d[0][1]);
	int i = 0, j = 1;
	while (j<n)
	{
		printf("%d %d\n",st[i][j].X+1,st[i][j].Y+1);
		PII q = prev[i][j];
		i=q.X;
		j=q.Y;
	}
	if (i<n) printf("%d\n",i+1);
	return 0;
}