#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 3e18;
const LL mod = 1e9 + 7;
const LL MAX = 64;

int n;
int k;
LL a[MAX];

int memo[MAX][MAX];

int can(LL L, int pos, int she)
{
	if (pos == n)
	{
		if (she == 0)
			return memo[pos][she] = 1;
		else
			return memo[pos][she] = 0;
	}

	if (she == 0)
		return memo[pos][she] = 0;

	if (memo[pos][she] != -1)
		return memo[pos][she];

	LL tut = 0;
	FOR(i, pos, n)
	{
		tut += a[i];
		if ((tut & L) != L)
			continue;

		if (can(L, i + 1, she - 1))
			return memo[pos][she] = 1;
	}

	return memo[pos][she] = 0;
}

bool can(LL L)
{
	FILL(memo, -1);
	return can(L, 0, k);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];

	LL ans = 0;

	RFOR(i, 60, 0)
	{
		LL tut = 1LL << i;
		if (can(ans + tut))
			ans += tut;
	}

	cout << ans << endl;
	cin >> n;
	return 0;
}