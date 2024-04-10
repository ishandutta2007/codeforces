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
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAXN = 1 << 7;
const LL MAX = 1 << 10;

int n, a, b;
bool ans[MAX][MAX];

void bad()
{
	cout << "NO" << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> a >> b;

	if (n == 1)
	{
		if (a != 1 || b != 1)
			bad();

		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}

	if (a != 1 && b != 1)
		bad();

	if (a == 1 && b == 1)
	{
		if (n < 4)
			bad();

		FOR(i, 0, n)
			ans[i][i + 1] = ans[i + 1][i] = 1;
	}
	else
	{
		if (a == 1)
		{
			FOR(i, 0, n)
				FOR(j, 0, n)
				if (i != j)
					ans[i][j] = 1;

			int curr = n;
			int ye = 1;
			while (curr != b)
			{
				--curr;
				ans[0][ye] = ans[ye][0] =  0;
				++ye;
			}
		}
		else
		{
			FOR(i, 0, n)
				FOR(j, 0, n)
				if (i != j)
					ans[i][j] = 1;

			int curr = n;
			int ye = 1;
			while (curr != a)
			{
				--curr;
				ans[0][ye] = ans[ye][0] = 0;
				++ye;
			}

			FOR(i, 0, n)
				FOR(j, 0, n)
				if (i != j)
					ans[i][j] ^= 1;
		}
	}

	cout << "YES" << endl;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
			cout << ans[i][j];
		cout << endl;
	}

	cin >> n;
	return 0;
}