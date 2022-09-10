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

#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
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
const LL MAX = 100;

int a, b, c, d;
int n = 50;
char ans[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "w", stdout);

	cin >> a >> b >> c >> d;
	cout << n << " " << n << endl;
	FOR(i, 0, n)
		FOR(j, 0, n)
		ans[i][j] = 'B';

	int she = a - 1;
	int last_column = 0;
	for (int i = 0; i < n; i += 2)
	{
		for (int j = 0; j < n; j += 2)
		{
			if (!she)
				break;

			--she;
			last_column = i;
			ans[i][j] = 'A';
		}
	}

	last_column += 2;

	FOR(i, last_column, n)
		FOR(j, 0, n)
		ans[i][j] = 'A';

	--b;

	for (int i = last_column + 1; i < n; i += 2)
	{
		for (int j = 0; j < n; j += 2)
		{
			if (b)
			{
				--b;
				ans[i][j] = 'B';
				continue;
			}

			if (c)
			{
				--c;
				ans[i][j] = 'C';
				continue;
			}
			
			if (d)
			{
				--d;
				ans[i][j] = 'D';
				continue;
			}
		}
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, n)
			cout << ans[i][j];
		cout << endl;
	}

	return 0;
}