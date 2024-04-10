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
int nn;

int gl_mx,gl_mn;
struct TimeTree
{
	int lh[N*4],rh[N*4];
	int incr[N*4];
	void make()
	{
		CLEAR(lh);
		CLEAR(rh);
		CLEAR(incr);
	}
	void modify(int v, int l, int r, int x, int by)
	{
		if (r < x) return;
		if (x <= l)
		{
			incr[v] += by;
			return;
		}
		if (incr[v])
		{
			lh[v]+=incr[v];
			rh[v]+=incr[v];
			incr[2*v]+=incr[v];
			incr[2*v+1]+=incr[v];
			incr[v]=0;
		}
		int mid = (l+r)/2;
		modify(v*2, l, mid, x, by);
		modify(v*2+1, mid+1, r, x, by);
		lh[v] = incr[v*2]+lh[v*2];
		rh[v] = incr[v*2+1]+rh[v*2+1];
	}
	void query(int v, int l, int r, int needle)
	{
		if (lh[v]+incr[v] > needle || rh[v]+incr[v] < needle)
			return;
		if (lh[v]+incr[v] == needle && rh[v]+incr[v] == needle)
		{
			gl_mn = min(gl_mn,l);
			gl_mx = max(gl_mx,r);
			return;
		}
		if (incr[v])
		{
			lh[v]+=incr[v];
			rh[v]+=incr[v];
			incr[2*v]+=incr[v];
			incr[2*v+1]+=incr[v];
			incr[v]=0;
		}
		int mid = (l+r)/2;
		query(v*2, l, mid, needle);
		query(v*2+1, mid+1, r, needle);
	}
} timet;

/*struct HappyTree
{
	int sum[N*4];
	int incr[N*4];
	void make()
	{
		CLEAR(sum);
		CLEAR(incr);
	}
	void modify(int v, int l, int r, int mml, int mmr)
	{
		if (r < mml || mmr < l) return;
		if (mml <= l && r <= mmr)
		{
			++incr[v];
			return;
		}
		if (incr[v])
		{
			sum[v] += r-l+1;
			incr[2*v]+=incr[v];
			incr[2*v+1]+=incr[v];
			incr[v]=0;
		}
		int mid = (l+r)/2;
		modify(v*2, l, mid, mml, mmr);
		modify(v*2+1, mid+1, r, mml, mmr);
		sum[v] = sum[v*2]+(mid-l+1)*incr[v*2] + sum[v*2+1]+(r-mid)*incr[v*2+1];
	}
	int get(int v, int l, int r, int x)
	{
		if (r < x || x < l) return 0;
		if (l==r)
		{
			return sum[v]+incr[v];
		}
		if (incr[v])
		{
			sum[v] += r-l+1;
			incr[2*v]+=incr[v];
			incr[2*v+1]+=incr[v];
			incr[v]=0;
		}
		int mid = (l+r)/2;
		return get(v*2, l, mid, x) + get(v*2+1, mid+1, r, x);
	}
} happyt;*/

template <class T> class Summator { public:
	T a[N]; int n;
	inline void make(int nn) { n=nn; CLEAR(a); }
	inline void modify(int x, T by)	{ a[x] += by;
		for (int i=1;1;i<<=1) if ((x&i)==0) {
			if ((x|=i)>=n) break;
			a[x] += by; } }
	inline T sum(int x) { T res=0;
		for (; x >= 0; x = (x&(x+1))-1) res += a[x];
		return res; }
	inline T sum(int l, int r) { T res=0; l--;
		for (; r > l; r = (r&(r+1))-1) res += a[r];
		for (; l > r; l = (l&(l+1))-1) res -= a[l];
		return res; } };
Summator<int> happyt;

int m;
VI nums;
int type[N];
PII brd[N];
int by[N];
int init[N];
VI byend[2][2][N];

int main()
{
	//freopen("data.in","r",stdin);
	FOR(len,1,4) REP(mask,1<<len)
	{
		int x = 0;
		REPD(i,len)
			x = x*10 + ((mask&(1<<i))?7:4);
		nums.pb(x);
	}
	SORT(nums);

	scanf("%d%d",&nn,&m);
	REP(i,nn) scanf("%d",&init[i]);
	CLEAR(by);
	REP(i,m)
	{
		char buf[256];
		scanf("%s",buf);
		type[i] = strcmp(buf,"count")==0;
		scanf("%d%d",&brd[i].X,&brd[i].Y);
		if (type[i] == 0)
			scanf("%d",&by[i]);
		--brd[i].X;
		--brd[i].Y;
		byend[type[i]][0][brd[i].X].pb(i);
		byend[type[i]][1][brd[i].Y].pb(i);
	}
	timet.make();
	happyt.make(m+1);
	REP(x,nn)
	{
		REP(i,SZ(byend[0][0][x]))
		{
			int id = byend[0][0][x][i];
			timet.modify(1,0,m-1,id,by[id]);
		}
		REP(i,SZ(byend[1][0][x]))
		{
			int id = byend[1][0][x][i];
			by[id] -= happyt.sum(id);
		}
		REP(ihappy,SZ(nums))
		{
			gl_mn = m+1;
			gl_mx = -m;
			timet.query(1,0,m-1,nums[ihappy]-init[x]);
			if (gl_mn <= gl_mx)
			{
				happyt.modify(gl_mn,+1);
				happyt.modify(gl_mx+1,-1);
			}
		}
		REP(i,SZ(byend[0][1][x]))
		{
			int id = byend[0][1][x][i];
			timet.modify(1,0,m-1,id,-by[id]);
		}
		REP(i,SZ(byend[1][1][x]))
		{
			int id = byend[1][1][x][i];
			by[id] += happyt.sum(id);
		}
	}
	REP(i,m) if (type[i]==1)
		printf("%d\n",by[i]);
	return 0;
}