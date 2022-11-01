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

int bitcnt(LL x)
{
	int res = 0;
	for (; x; x&=x-1)
		res++;
	return res;
}

#define MS 51
void mulModMatr(int n, bool a[MS][MS], bool b[MS][MS], bool c[MS][MS]) {
	static bool cc[MS][MS];
	CLEAR(cc);
	REP(i,n) REP(j,n) REP(k,n) if (a[i][k] && b[k][j]) cc[i][j]^=1;
	REP(i,n) REP(j,n) c[i][j]=cc[i][j]; }
void powModMatr(int n, LL k, bool aa[MS][MS], bool cc[MS][MS]) {
	static bool a[MS][MS],c[MS][MS];
	REP(i,n) REP(j,n) a[i][j]=aa[i][j];
	REP(i,n) REP(j,n) c[i][j]=(i==j);
	for (; k; k/=2,mulModMatr(n,a,a,a)) if (k&1) mulModMatr(n,a,c,c);
	REP(i,n) REP(j,n) cc[i][j]=c[i][j]; }

bool test(int n, LL c)
{
	int cc = 0;
	REP(i,n)
	{
		cc <<= 1;
		cc ^= c & 1;
		c >>= 1;
	}
	c = cc;
	LL a = 1;
	REP(i,(1<<n)-1)
	{
		if (i > 0 && a == 1) return false;
		a = ((a>>1) ^ ((bitcnt(a&c) % 2 == 1) << (n-1)));
		if (!a) return false;
	}
	return a==1;
}

VI divs;

bool test2(int n, LL c)
{
	bool a[MS][MS],r[MS][MS];
	CLEAR(a);
	REP(i,n-1)
		a[i+1][i] = true;
	REP(i,n)
		a[0][i] = (c & (1LL<<i)) != 0;
	powModMatr(n,(1LL<<n)-1,a,r);
	REP(i,n) REP(j,n)
		if (r[i][j] != (i==j))
			return false;
	REP(ii,SZ(divs))
	{
		powModMatr(n,((1LL<<n)-1)/divs[ii],a,r);
		REP(i,n) REP(j,n)
			if (r[i][j] != (i==j))
				goto ok;
		return false;
ok:
		;
	}
	return true;
}

vector<LL> answers;

void go(int n)
{
	divs.clear();
	cout << "=== " << n << endl;
	int cnt = 0;
	LL pw = (1LL<<n)-1;
	REP(i,1000000) if (i>1)
		if (pw%i == 0)
		{
			while (pw%i == 0) pw/=i;
			divs.pb(i);
		}
	if (pw > 1 && pw > 100000000000LL)
		cout << "? " <<  pw << endl;
	REP(step,1000000)
	//for (LL mask = 1; mask < (1LL<<n); mask++)
	{
		LL mask = 0;
		REP(i,n)
			mask = mask*2 + rand()%2;
		if (test2(n,mask))
		{
			if (n < 20 && !test(n,mask))
				cout << "!!!!!!!!!!!!! FUCK" << endl;
			REP(i,n)
				cout << ((mask & (1LL<<i)) != 0);
			cout << "   " << mask << endl;
			answers.push_back(mask);
			return;
			cnt++;
		}
	}
	//cout << "bad";
	cout << "NOT FOUND";
}

const LL results[51] = {
0,
0,
3,
6,
12,
30,
33,
72,
150,
380,
873,
2022,
3269,
4477,
10966,
17216,
63390,
67997,
228136,
345652,
831921,
1959090,
4110207,
4230998,
14267079,
19953845,
46262416,
115323795,
233201634,
510773499,
692680299,
1089257766,
2684454780,
8352759422,
16548130824,
20563101117,
60389846922,
81128304847,
213467595574,
456552423589,
602447979113,
1750365006256,
3563089605818,
7186372434437,
13048716715978,
20964269033527,
69444645767825,
133536698030797,
194500634974621,
420646283225931,
764309343199660 };

int main()
{
	//freopen("data.in","r",stdin);
	//cout << test(3,3) << endl;
	/*answers.assign(2,0);
	FOR(n,2,50)
		go(n);
	cout << "\n\n\n";
	FOR(n,0,50) cout << answers[n] << endl;*/
	int n;
	cin >> n;
	REP(i,n)
		printf(" %d"+(i==0), (results[n] & (1LL<<i)) != 0 ? 1 : 0);
	printf("\n");
	REP(i,n)
		printf(" 1"+(i==0));
	printf("\n");
	return 0;
}