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
int a[N];
int b[N];
int iter;
int q[N];

int get(int x, bool st = false)
{
	++iter;
	FOR(i,2,x)
	{
		int grow = i*(i+1)/2;
		if (grow > x) break;
		if ((x-grow) % i == 0)
		{
			int s = 0;
			int add = (x-grow) / i + 1;
			REP(j,i)
				s ^= a[add+j];
			q[s] = iter;
			if (st) b[i] = s;
		}
	}
	int res = 0;
	while (q[res] == iter) ++res;
	return res;
}

int main()

{
	FILL(q,-1);
	iter=0;
	CLEAR(a);
	REP(x,N)
	{
		a[x] = get(x);
	}
	scanf("%d",&n);
	int res;
	if (a[n] == 0)
		res = -1;
	else
	{
		FILL(b,-1);
		get(n,true);
		res = 0;
		while (b[res] != 0) res++;
	}
	printf("%d\n",res);
	return 0;
}