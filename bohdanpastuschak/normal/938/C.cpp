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
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const LL MAXN = 5e3 + 7;

VLL get(LL x)
{
	VLL res;
	for(LL i = 1; i*i <= x; ++i)
		if (x%i == 0)
		{
			res.push_back(i);
			if (i*i != x)
				res.push_back(x / i);
		}
	sort(ALL(res));
	return res;
}

void solve()
{
	LL x;
	cin >> x;
	if (x % 4 == 2)
	{
		cout << -1 << endl;
		return;
	}

	if (x == 0)
	{
		cout << "1 1" << endl;
		return;
	}

	auto d = get(x);
	for (auto i : d)
	{
		if ((i + x / i) & 1)
			continue;

		LL n = (i + x / i) >> 1;
		LL k = n - i;
		if (k < 0)
			continue;

		LL L = 1, R = n, M;
		while (R - L > 1)
		{
			M = (L + R) >> 1;
			if (k < n / M)
				L = M;
			else
				R = M;
		}

		if (k == n / L)
			M = L;
		else
			M = R;

		if (n / M == k)
		{
			cout << n << " " << M << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int t;
	cin >> t;
	FOR(i, 0, t)
		solve();


	return 0;
}