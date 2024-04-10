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

template<class T> inline T gcd(T a,T b) {
	if(a<0)a=-a; if(b<0)b=-b; if(a<b)swap(a,b);
	while (b) {T t = b; b=a%b; a=t;} return a; }
template <typename T> T euclide(T a, T b, T &x, T &y) {
	if (a<0) { T g = euclide(-a,b,x,y); x=-x; return g; }
	if (b<0) { T g = euclide(a,-b,x,y); y=-y; return g; }
	if (a<b) return euclide(b,a,y,x);
	if (!b) { x = 1; y = 0; return a; }
	T x1, y1;
	T g = euclide(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return g; }
template<class T> inline T inverse(T a, T n)
{	T x,y; euclide(a,n,x,y); return ((x%n)+n)%n;}

#define N 1050
#define MOD 1000000007
int n,k;
VI nums;
int cnt[N],rest;
int d[N][N];
int cnk[N][N];
int fact[111000];

int getcnk(int n, int k)
{
	if (k < 0 || k > n) return 0;
	return ((fact[n]*(LL)inverse<LL>(fact[k],MOD))%MOD*(LL)inverse<LL>(fact[n-k],MOD))%MOD;
}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	CLEAR(cnk);
	REP(i,N)
	{
		cnk[i][0]=1;
		FOR(j,1,i)
			cnk[i][j] = (cnk[i-1][j-1]+cnk[i-1][j])%MOD;
	}
	FOR(len,1,9) REP(mask,1<<len)
	{
		int x = 0;
		REPD(i,len)
			x = x*10 + ((mask&(1<<i))?7:4);
		nums.pb(x);
	}
	fact[0]=1;
	FOR(i,1,111000-1)
		fact[i]=(fact[i-1]*(LL)i)%MOD;
	SORT(nums);
	//fprintf(stderr,"%d\n",SZ(nums));

	scanf("%d%d",&n,&k);
	rest=0;
	CLEAR(cnt);
	REP(i,n)
	{
		int x;
		scanf("%d",&x);
		int p = lower_bound(ALL(nums),x)-nums.begin();
		if (p < SZ(nums) && nums[p]==x)
			++cnt[p];
		else
			++rest;
	}
	CLEAR(d);
	d[0][0]=1;
	int top = min(k,SZ(nums));
	REP(i,SZ(nums))
	{
		FOR(x,0,top)
		{
			d[i+1][x] = (d[i+1][x]+d[i][x])%MOD;
			if (x+1 <= top)
				d[i+1][x+1] = (d[i+1][x+1]+d[i][x]*(LL)cnt[i])%MOD;
		}
	}
	int res = 0;
	FOR(x,0,top)
		res = (res + getcnk(rest,k-x)*(LL)d[SZ(nums)][x])%MOD;
	printf("%d\n",res%MOD);
	return 0;
}