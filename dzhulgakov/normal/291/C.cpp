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

int k,n;
vector<LL> a,b;

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&k);
	a.resize(n);
	REP(i,n)
	{
		LL ip = 0;
		REP(j,4)
		{
			int x;
			scanf("%d",&x);
			ip = (ip << 8) + x;
			if (j<3) scanf(".");
		}
		a[i]=ip;
	}
	SORT(a);
	LL mask = 0;
	for (int bit = 31; bit > 0; --bit)
	{
		mask |= 1LL << bit;
		b.resize(n);
		REP(i,n) b[i]=a[i]&mask;
		UNIQUE(b);
		if (b.size() == k)
		{
			REPD(i,4)
			{
				printf("%d",(int)((mask>>(i*8))&0xff));
				if (i)printf(".");
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}