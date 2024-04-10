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
#include <unordered_map>
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
const LL MAX = 2e5 + 7;
const LL MAXN = 101;
const LD EPS = 1e-9;

int n;
const int To = 1 << 17;
int p2[20];
int DP[MAXN][To];
int best[MAXN][To];
int primes[17];
int index[MAXN];
int a[MAXN];
VI d[MAXN];
int M[MAXN];

inline void compute(int x)
{
	int y = x;
	for (int i = 2; i * i <= x; ++i)
		if (x%i == 0)
		{
			d[y].push_back(i);
			while (x%i == 0)
				x /= i;
		}

	if (x != 1)
		d[y].push_back(x);

	sort(ALL(d[y]));
}

inline bool is(int x)
{
	if (x == 1)
		return 0;

	compute(x);
	for(int i = 2; i * i <= x; ++i)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	p2[0] = 1;
	FOR(i, 1, 20)
		p2[i] = 2 * p2[i - 1];

	FOR(i, 1, 61)
		if (is(i))
			primes[n] = i, index[i] = n++;

	cin >> n;
	FOR(i, 1, n + 1)
		cin >> a[i];

	FOR(i, 2, MAXN)
	{
		for (auto j : d[i])
			M[i] |= p2[index[j]];
	}

	int ans = INF;
	
	FOR(i, 0, MAXN)
		FOR(j, 0, To)
		DP[i][j] = INF;

	DP[0][0] = 0;
	FOR(i, 1, n + 1)
	{
		FOR(j, 0, To)
		{
			FOR(b, 1, a[i] * 2)
			{
				if (j & M[b])
					continue;

				if (DP[i][j | M[b]] > abs(a[i] - b) + DP[i - 1][j])
				{
					DP[i][j | M[b]] = abs(a[i] - b) + DP[i - 1][j];
					best[i][j | M[b]] = b;
				}
			}
		}
	}

	FOR(i, 0, To)
		ans = min(ans, DP[n][i]);	

	//cout << ans << endl;
	VI res(n + 1, 0);
	int ind = 0;
	FOR(i, 1, To)
		if (ans == DP[n][i])
		{
			ind = i;
			break;
		}

	int vz = 0;
	RFOR(i, n + 1, 1)
	{
		res[i] = best[i][ind];
		vz |= M[res[i]];

		ans -= abs(a[i] - best[i][ind]);
		ind = 0;
		FOR(j, 1, To)
			if (!(j & vz) && ans == DP[i - 1][j])
			{
				if (j & vz)
					continue;

				ind = j;
				break;
			}
	}

	FOR(i, 1, SZ(res))
		cout << res[i] << " ";

	cin >> n;
	return 0;
}