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
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
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
const LD EPS = 1e-6;

int n;
int m;
inline int type(char x)
{
	if (x >= '0' && x <= '9')
		return 0;
	
	if (x >= 'a' &&  x <= 'z')
		return 1;
		
	return 2;
}

inline int dist(int i)
{
	return min(i, m - i);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	VVCH A(n, VCH(m));
	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> A[i][j];

	VVI a(n, VI(m));
	FOR(i, 0, n)
		FOR(j, 0, m)
		a[i][j] = type(A[i][j]);

	VVI DP(n, VI(8, m*n*3));

	FOR(j, 0, m)
		DP[0][1 << a[0][j]] = min(DP[0][1 << a[0][j]], dist(j));

	DP[0][0] = 0;
	FOR(i, 1, n)
	{
		FOR(j, 0, 8)
			DP[i][j] = DP[i - 1][j];

		FOR(j, 0, 8)
		{
			FOR(x, 0, 3)
				if (j & (1 << x))
					continue;
				else
				{
					int best = m * n * 3;
					FOR(k, 0, m)
						if (a[i][k] == x)
							best = min(best, dist(k));

					DP[i][j | (1 << x)] = min(DP[i][j | (1 << x)], DP[i - 1][j] + best);
				}
		}
	}

	int ans = n * m * 3;
	FOR(i, 0, n)
		ans = min(ans, DP[i][7]);

	cout << ans;
	cin >> n;
	return 0;
}