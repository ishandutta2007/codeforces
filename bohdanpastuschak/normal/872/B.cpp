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
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<char> VCH;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define X first
#define Y second
#define MP make_pair

#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i,a,b)  for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i= (b) - 1; i >= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)

const LL MAXN = 1000001;
const LL INF = 1e9;
const LL mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	VLL a(n);
	FOR(i, 0, n)
		cin >> a[i];

	if (k == 1)
	{
		LL mi = a[0];
		FOR(i, 1, n)
			mi = min(mi, a[i]);

		cout << mi;
		return 0;
	}

	if (k == 2)
	{
		VLL pref(n), suf(n);
		pref[0] = a[0];
		FOR(i, 1, n)
			pref[i] = min(pref[i - 1], a[i]);

		suf[n - 1] = a[n - 1];
		RFOR(i, n - 1, 0)
			suf[i] = min(suf[i + 1], a[i]);

		LL ans = max(a[0], a[n - 1]);
		LL curr;
		FOR(i, 1, n)
		{
			curr = max(pref[i - 1], suf[i]);
			ans = max(ans, curr);
		}

		cout << ans;
		return 0;
	}

	LL ma = a[0];
	FOR(i, 1, n)
		ma = max(ma, a[i]);

	cout << ma;
	return 0;
}