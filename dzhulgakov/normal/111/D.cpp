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
#define MOD 1000000007
int n,m,kk;
int d[N][N],cnk[N][N],fact[N*2],revfact[N*2];
int pw[N];

LL fastpow(LL x, LL n, LL mod) { LL res=1;
	while (n)
		if (n%2) { res=(res*x)%mod; n--; }
		else { x=(x*x)%mod; n/=2; }
	return res; }

template <typename T> T euclide(T a, T b, T &x, T &y) {
	if (a<0) { T g = euclide(-a,b,x,y); x=-x; return g; }
	if (b<0) { T g = euclide(a,-b,x,y); y=-y; return g; }
	if (a<b) return euclide(b,a,y,x);
	if (!b) { x = 1; y = 0; return a; }
	T x1, y1;
	T g = euclide(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
// in oder to avoid overflow:
//	T d = x/b; x -= d*b; y += d*a;
	return g; }
template<class T> inline T inverse(T a, T n)
{	T x,y; euclide(a,n,x,y); return ((x%n)+n)%n;}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d",&n,&m,&kk);
	d[0][0]=1;
	REP(i,n) REP(j,i+1)
	{
		d[i+1][j] = (d[i+1][j] + d[i][j]*(LL)j)%MOD;
		d[i+1][j+1] = (d[i+1][j+1] + (LL)d[i][j])%MOD;
	}
	if (m>=2)
		REP(i,n+1)
			pw[i] = fastpow(i,n*(m-2),MOD);
	if (n*(m-2) == 0)
		pw[0]=1;
	else
		pw[0]=0;
	CLEAR(cnk);
	cnk[0][0]=1;
	FOR(i,1,n)
	{
		cnk[i][0]=1;
		FOR(j,1,i)
			cnk[i][j] = (cnk[i-1][j-1]+cnk[i-1][j])%MOD;
	}
	fact[0]=1;
	revfact[0]=1;
	FOR(i,1,n*2)
	{
		fact[i] = (fact[i-1]*(LL)i)%MOD;
		revfact[i] = (revfact[i-1]*(LL)(kk+1-i))%MOD;
	}
	LL res = 0;
	if (m>=2)
	{
		FOR(k,1,min(n,kk))
		{
			LL base = (d[n][k]*(LL)d[n][k])%MOD;
			FOR(p,0,k)
			{
				LL t = ((((revfact[2*k-p]*(LL)cnk[k][p])%MOD*(LL)fact[p])%MOD*(LL)base)%MOD*cnk[k][p])%MOD;
				res = (res + t*(LL)pw[p])%MOD;
			}
		}
	}
	else
	{
		FOR(k,1,min(n,kk))
			res = (res + d[n][k]*(LL)revfact[k])%MOD;
	}
	res %= MOD;
	printf("%d\n",(int)res);
	return 0;
}