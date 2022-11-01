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

int n,m,p,k;
bool sw;
int val[1024];
int cnt[1024];

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	sw = n<m;
	if (sw) swap(n,m);
	CLEAR(val);
	CLEAR(cnt);
	REP(i,k)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		x--;y--;
		if (sw) swap(x,y);
		if (v==-1)
		{
			val[x]^=1;
		}
			cnt[x]++;
	}
	scanf("%d",&p);
	bool was = false;
	bool bad = false;
	int fr = 0;
	REP(i,n)
	{
		if (!was && cnt[i] == 0)
		{
			was = true;
			continue;
		}
		if (cnt[i] == m)
		{
			if (val[i] != 1)
				bad = true;
			continue;
		}
		fr += m-cnt[i]-1;
	}
	if ((n+m)%2 != 0)
		bad = true;
	int res = 1;
	if (bad) res = 0;
	else
	{
		REP(i,fr)
			res = (res*2)%p;
	}
	printf("%d\n",res);
	return 0;
}