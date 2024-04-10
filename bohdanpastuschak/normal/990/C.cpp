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
const LL MAX = 1 << 19;

int n;
string a[MAX];
VI balance_minus[MAX];
int balance[MAX];
int least[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	int mibal = 0;
	FOR(i, 0, n)
	{
		int ye = 0, curr = 0;
		FOR(j, 0, SZ(a[i]))
		{
			if (a[i][j] == '(')
				++ye;
			else
				--ye;

			curr = min(curr, ye);
		}

		balance[i] = ye;
		least[i] = curr;
		mibal = min(mibal, ye);
		if (ye <= 0)
			balance_minus[-ye].push_back(least[i]);
	}

	FOR(i, 0, -mibal + 1)
		sort(ALL(balance_minus[i]));

	LL ans = 0;

	FOR(i, 0, n)
	{
		if (least[i] < 0)
			continue;

		int tut = balance[i];
		auto it = lower_bound(ALL(balance_minus[tut]), -tut);
		ans += abs(distance(balance_minus[tut].end(), it));
	}

	cout << ans << endl;
	cin >> n;
	return 0;
}