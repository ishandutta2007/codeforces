#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 0.5;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const LL MAXN = 5e3 + 7;

LL n;
LL k;
LL ans;

inline LL power(LL x, LL y)
{
	LL res = 1;
	while (y)
	{
		if (y & 1)
			res = (res * x) % mod;

		x = (x*x) % mod;
		y >>= 1;
	}
	return res;
}

LL delta;
LL memo[MAXN][MAXN];

inline LL get(LL x, LL y)
{
	if (y < 0)
		return 0;

	if (memo[x][y] != -1)
		return memo[x][y];

	if (x == 0)
		return memo[x][y] = 1;

	LL res = (y + delta);
	res *= (((2 * get(x - 1, y) - get(x - 1, y - 1)) % mod + mod)%mod);
	res %= mod;
	return memo[x][y] = res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> k;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	FILL(memo, -1);
	ans = power(2, n);
	ans *= power(power(2, k), mod - 2);
	ans %= mod;

	LL C = n / MAXN;
	--C;
	if (n < MAXN)
	{
		delta = 0;
		ans *= get(k, n);
	}
	else
	{
		delta = MAXN * C;
		n -= MAXN * C;
		ans *= get(k, n);
	}
	ans %= mod;
	cout << ans;
	cin >> n;
	return 0;
}