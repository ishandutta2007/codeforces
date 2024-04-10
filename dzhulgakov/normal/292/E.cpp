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
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

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

typedef rope<int> T;

T a,b;
vector<int> aa,bb;
int n,m;

int main()
{
    //freopen("data.in","r",stdin);

	scanf("%d%d",&n,&m);
	aa.resize(n);
	bb.resize(n);
	REP(i,n)
	{
		int x;
		scanf("%d",&x);
		aa[i]=x;
	}
	REP(i,n)
	{
		int x;
		scanf("%d",&x);
		bb[i]=x;
	}
	a = T(&aa[0],n);
	b = T(&bb[0],n);
	REP(i,m)
	{
		int type;
		scanf("%d",&type);
		if (type == 2)
		{
			int x;
			scanf("%d",&x);
			--x;
			printf("%d\n",(int)b[x]);
		}
		else
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			--x;--y;
			b.replace(y,k, a.begin()+x,a.begin()+x+k);
		}
	}
	return 0;
}