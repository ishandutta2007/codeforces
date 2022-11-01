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
#include <bitset>

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

#define N 128

typedef bitset<512> BS;
int mem[N][4][4];

int go(int n, int m1, int m2)
{
	if (n==1) 
	{
		m1|=m2;
		m2|=m1;
	}
	int& res = mem[n][m1][m2];
	if (res != -1) return res;
	BS bs;
	REP(i,n) REP(col,2)
	{
		int mask = 0;
		if (i == 0) mask = m1;
		if (i == n-1) mask = m2;
		if (mask & (1<<col)) continue;
		int sum = 0;
		if (i > 0) sum ^= go(i,m1,1<<(1-col));
		if (i < n-1) sum ^= go(n-i-1,1<<(1-col),m2);
		bs.set(sum);
	}
	REP(i,512) if (!bs[i])
		return res = i;
	return res = 0;
}

int n,k;
PII b[N];


/*int mem2[1024][1024];
int go2(int n, int m1, int m2)
{
	int& res = mem2[m1][m2];
	if (res != -1) return res;
	FOR(i,1,n)
	{
		if (!(m1 & (1<<i)))
			if (go2(n,m1|(1<<i),m2|(7<<(i-1))) == 0)
				return res = 1;
		if (!(m2 & (1<<i)))
			if (go2(n,m1|(7<<(i-1)),m2|(1<<i)) == 0)
				return res = 1;
	}
	return res = 0;
}

bool solve2()
{
	int mm1=0,mm2=0;
	FOR(i,1,k)
	{
		if (b[i].Y==1)
		{
			mm1 |= 1<<b[i].X;
			mm2 |= 7<<(b[i].X-1);
		}
		else
		{
			mm1 |= 7<<(b[i].X-1);
			mm2 |= 1<<b[i].X;
		}
	}
	FILL(mem2,-1);
	return !go2(n,mm1,mm2);
}*/

bool solve()
{
	FILL(mem,-1);
	b[0]=PII(0,0);
	b[k+1]=PII(n+1,0);
	sort(b,b+k+2);
	int sum = 0;
	REP(i,k+1)
	{
		if (b[i].X+1 == b[i+1].X) continue;
		int val = go(b[i+1].X - b[i].X - 1, b[i].Y, b[i+1].Y);
		sum^=val;
	}
	return sum == 0;
}

int main()
{
	/*n = 5;
	REP(mask,1<<(2*n))
	{
		k=0;
		REP(i,n)
		{
			int val = mask>>(2*i);
			val &= 3;
			if (val ==1 || val==2)
				b[++k]=PII(i+1,val);
		}
		bool r1 = solve();
		bool r2 = solve2();
		if (r1!=r2)
			printf("BAD!\n");
	}
	return 0;*/
	//freopen("pal.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&k);
	FOR(i,1,k)
		scanf("%d%d",&b[i].X,&b[i].Y);
	printf("%s\n",solve()?"LOSE":"WIN");

	//printf("%s\n",solve2()?"LOSE":"WIN");
	return 0;
}