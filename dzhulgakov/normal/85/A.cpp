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

char a[4][128];

int main()
{
//	freopen("data.in","r",stdin);

	int n;
	scanf("%d",&n);
	CLEAR(a);
	if (n%2 == 1)
	{
		REP(i,n-1)
		{
			if (i%4 < 2)
				a[0][i] = 'a';
			else
				a[0][i] = 'b';
			if (i%4 < 2)
				a[1][i] = 'c';
			else
				a[1][i] = 'd';
		}
		a[0][n-1] = 'w';
		a[1][n-1] = 'w';
		REP(i,n-1)
		{
			if (i%4 < 2)
				a[2][i+1] = 'e';
			else
				a[2][i+1] = 'f';
			if (i%4 < 2)
				a[3][i+1] = 'g';
			else
				a[3][i+1] = 'h';
		}
		a[2][0] = 'q';
		a[3][0] = 'q';
	}
	else
	{
		REP(i,n)
		{
			if (i%4 < 2)
				a[0][i] = 'a';
			else
				a[0][i] = 'b';
			if (i%4 < 2)
				a[3][i] = 'c';
			else
				a[3][i] = 'd';
		}
		REP(i,n-2)
		{
			if (i%4 < 2)
				a[1][i+1] = 'e';
			else
				a[1][i+1] = 'f';
			if (i%4 < 2)
				a[2][i+1] = 'g';
			else
				a[2][i+1] = 'h';
		}
		a[1][0] = a[2][0] = 'x';
		a[1][n-1] = a[2][n-1] = 'y';
	}
	REP(i,4) printf("%s\n",a[i]);
	return 0;
}