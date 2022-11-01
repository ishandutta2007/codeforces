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

void TridiagonalSolve (const double *a, const double *b, double *c, double *d, double *x, unsigned int n){
 
	c[0] /= b[0];
	d[0] /= b[0];
	for (int i = 1; i < n; i++){
		double id = 1 / (b[i] - c[i-1] * a[i]); 
		c[i] *= id;	                         
		d[i] = (d[i] - d[i-1] * a[i]) * id;
	}
	x[n - 1] = d[n - 1];
	for (int i = n - 2; i >= 0; i--)
		x[i] = d[i] - c[i] * x[i + 1];
}

#define N 1024
int n,m,row,col;
double a[N],aa[N];

void go(const double *y, double *res)
{
	static double a[N],b[N],c[N],d[N];
	REP(i,m)
	{
		a[i]=b[i]=c[i]=d[i]=0;
		int moves = 2+(i>0)+(i<m-1);
		b[i]+=1.0;
		if (i>0)
			a[i] -= 1.0/moves;
		if (i<m-1)
			c[i] -= 1.0/moves;
		b[i] -= 1.0/moves;
		d[i] += y[i]/moves;
		d[i] += 1.0;
	}
	TridiagonalSolve(a,b,c,d,res,m);
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d%d%d",&n,&m,&row,&col);
	n = n-row;
	col--;
	CLEAR(a);
	REP(i,n)
	{
		go(a,aa);
		memcpy(a,aa,sizeof a);
	}
	printf("%.10lf\n",a[col]);
	return 0;
}