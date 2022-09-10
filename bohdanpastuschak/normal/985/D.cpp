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
const LD EPS = 1e-8;
const LL INF = 1e9;
const LL LINF = 5e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 17;

LL n, h;

inline LL get(LL x, LL M)
{
	return x * (M + 1) + M * (M + 1) / 2 + (x + M) * (x + M - 1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> h;
	LL ans = LINF;

	LD H = h, N = n;
	bool is = 0;
	if (H *(H + 1) / 2.0 < N)
	{
		if (h*(h + 1) / 2 < n)
			is = 1;
	}

	if (!is)
	{
		LL L = 1, R = 2e9, M;
		while (R - L > 1)
		{
			M = (L + R) / 2LL;
			if (M*(M + 1) / 2 >= n)
				R = M;
			else
				L = M;
		}

		M = L;
		if (M*(M + 1) / 2 < n)
			M = R;

		cout << M << endl;
		return 0;
	}

	LL L = 1, R = 2e9, M;
	while (R - L > 1)
	{
		M = (L + R) / 2LL;
		LL val = get(h, M);

		if (val >= n)
			R = M;
		else
			L = M;
	}

	M = L;
	if (get(h, M) < n)
		M = R;

	const int MAGIC = 100;

	for (LL i = max(0LL, M - MAGIC); i <= M + MAGIC; ++i)
	{
		LL val = get(h, i);
		if (val >= n)
		{
			ans = min(ans, h + 2 * i);
			continue;
		}

		LL she = n - val;
		LL treba = (she + h + i - 1) / (h + i);
		ans = min(ans, h + 2 * i + treba);
	}


	cout << ans << endl;
	cin >> n;
	return 0;
}