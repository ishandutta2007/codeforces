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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const LL INF = 2e9 + 1;
const LL LINF = 1e12;
const LL MAXN = 2e5 + 1;
const LD EPS = 1e-6;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int n;
	cin >> n;
	VLL a(n);
	FOR(i, 0, n)
		cin >> a[i];

	LL ans = 0;
	LL sum = 0;
	FOR(i, 0, n)
		sum += a[i];

	if (sum % 3)
	{
		cout << 0;
		return 0;
	}

	sum /= 3;
	LL ye = 0;
	VI ok;
	FOR(i, 0, n)
	{
		ye += a[i];
		if (ye == sum)
			ok.push_back(i + 1);
	}

	ye = 0;
	VI ok2;
	RFOR(i, n, 0)
	{
		ye += a[i];
		if (ye == sum)
			ok2.push_back(n - i);
	}

	sort(ALL(ok));
	sort(ALL(ok2));

	for (auto i : ok)
	{
		if (ok2[0] + i >= n)
			break;

		if (ok2.back() + i < n)
		{
			ans += SZ(ok2);
			continue;
		}

		int L = 0, R = SZ(ok2), M;
		while (R - L > 1)
		{
			M = (L + R) / 2;
			if (ok2[M] + i >= n)
				R = M;
			else
				L = M;
		}
		if (ok2[L] + i < n)
			M = L;
		else
			M = R;

		ans += (M + 1);
	}

	cout << ans;
	cin >> n;
	return 0;
}