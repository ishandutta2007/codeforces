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
#include <complex>
#include <stdio.h>
#include <unordered_set>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
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

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL MAXN = 1e5 + 1;

inline LL power(LL x, int y)
{
	LL res = 1;
	while (y)
	{
		if (y & 1)
			res = (res*x) % mod;
		x = (x*x) % mod;
		y >>= 1;
	}
	return res;
}

VLL F;

inline LL C(int n, int k)
{
	if (n < k)
		swap(n, k);
	LL res = F[n];

	res *= power(F[k], mod - 2);
	res %= mod;
	res *= power(F[n - k], mod - 2);
	res %= mod;
	return res;
}

VVLL DP;
VLL a;
int n;
int k;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	F.assign(MAXN, 1);
	FOR(i, 2, MAXN)
		F[i] = (F[i - 1] * i) % mod;

	cin >> n >> k;
	a.assign(n, 0);
	FOR(i, 0, n)
		cin >> a[i];

	VLL AAA;
	int U = 0;
	bool ok;
	LL x;
	FOR(i, 0, n)
	{
		ok = 1;
		x = a[i];
		while (x)
		{
			if ((x % 10 != 4) && (x % 10 != 7))
				ok = 0;
			x /= 10;
		}

		if (!ok)
			++U;
		else
			AAA.push_back(a[i]);
	}

	a = AAA;
	n = SZ(a);

	sort(ALL(a));
	AAA = a;
	a.clear();
	LL curr = 1;

	FOR(i, 0, SZ(AAA) - 1)
		if (AAA[i] == AAA[i + 1])
			++curr;
		else
			a.push_back(curr), curr = 1;

	if (SZ(AAA))
		a.push_back(curr);
	LL ans = 0;
	n = SZ(a);

	LL K = min(n, k);

	DP.assign(n + 1, VLL(K + 1, 0));
	DP[0][0] = 1;

	FOR(i, 1, n + 1)
	{
		DP[i][0] = 1;
		FOR(x, 1, K + 1)
		{
			DP[i][x] = (DP[i - 1][x] + DP[i - 1][x - 1] * a[i - 1]) % mod;
		}
	}	

	FOR(x, 0, min(U, k) + 1)
		if (k - x <= K)
			ans += (C(U, x) * DP[n][k - x]) % mod;

	ans %= mod;
	cout << ans;
	cin >> n;
	return 0;
}