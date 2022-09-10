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
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
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
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1000000007;
const LL MAXN = 507;

int n, m, k;
string a[MAXN];
int ye[MAXN];
int DP[MAXN][MAXN];
VI bad[MAXN];
int D[MAXN][MAXN];
int best[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> m >> k;
	int cnt = 0;
	FOR(i, 1, n + 1)
		cin >> a[i];
	
	FOR(i, 1, n + 1)
	{
		FOR(j, 0, SZ(a[i]))
			if (a[i][j] == '1')
				++cnt, ++ye[i], bad[i].push_back(j);
	}

	if (cnt <= k)
	{
		cout << 0;
		return 0;
	}

	FOR(i, 0, n + 1)
		FOR(j, 0, k + 1)
		DP[i][j] = INF;

	DP[0][0] = 0;

	FOR(i, 1, n + 1)
	{
		if (SZ(bad[i]) == 0)
			continue;

		FOR(j, 0, MAXN)
			FOR(z, 0, MAXN)
			D[j][z] = bad[i].back() - bad[i][0] + 1;

		D[ye[i]][0] = D[0][ye[i]] = 0;
		FOR(j, 1, ye[i])
			D[j][ye[i] - j] = 0;

		FOR(j, 1, ye[i])
			D[j][0] = bad[i][ye[i] - 1] - bad[i][j] + 1;

		FOR(j, 1, ye[i])
			D[0][j] = bad[i][ye[i] - j - 1] - bad[i][0] + 1;

		FOR(x, 1, ye[i])
		{
			FOR(y, 1, ye[i])
			{
				if (x + y >= ye[i])
					break;

				D[x][y] = 1 + bad[i][ye[i] - y - 1] - bad[i][x];
			}
		}

		FOR(j, 0, k + 1)
			best[i][j] = bad[i].back() - bad[i][0] + 1;

		FOR(j, 0, k + 1)
			FOR(z, 0, k + 1)
			if (j + z <= k)
				best[i][j + z] = min(best[i][j + z], D[j][z]);
	}

	FOR(i, 1, n + 1)
	{
		FOR(pr, 0, k + 1)
		{
			FOR(j, 0, ye[i] + 1)
			{
				if (j + pr > k)
					break;

				DP[i][j + pr] = min(DP[i][j + pr], DP[i - 1][pr] + best[i][j]);
			}
		}
	}

	cout << DP[n][k];
	cin >> n;
	return 0;
}