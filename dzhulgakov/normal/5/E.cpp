#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
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

int n;
int aa[2048000];
int * a;
PII st[1024000];
int k;
bool match0[1024000];

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	REP(i,n) scanf("%d",aa+i);
	int mx = 0;
	REP(i,n)
		if (aa[i]>aa[mx])
			mx=i;
	REP(i,n) aa[i+n]=aa[i];
	a = aa+mx;
	k=1;
	st[0]=PII(a[0],1);
	LL res = 0;
	CLEAR(match0);
	REP(i,n) if (i>0)
	{
		while (st[k-1].first < a[i])
		{
			res += st[k-1].second;
			k--;
		}
		if (st[k-1].first == a[i])
		{
			res += st[k-1].second;
			st[k-1].second++;
			if (st[0].first > a[i])
				res++;
		}
		else
		{
			st[k++]=PII(a[i],1);
			res++;
		}
		match0[i] = k==1 || k==2 && st[0].second == 1;
	}
	int curmx = 0;
	REPD(i,n) if (i>0)
	{
		curmx = max(curmx,a[i]);
		if (a[i]==curmx && !match0[i]) res++;
	}
	printf("%lld\n",res);
	return 0;
}