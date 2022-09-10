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
#include <tuple>
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
#define previous fake_previous
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
const LL MAXN = 1000001;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	LL n, m;
	cin >> n >> m;

	VLL a(n);
	FOR(i, 0, n)
		cin >> a[i], a[i] %= m;

	LL ans = 0;

	VLL t_a;
	FOR(i, 0, n)
		if (a[i])
			t_a.push_back(a[i]);

	a = t_a;
	n = SZ(a);

	LL p2[20];
	p2[0] = 1;
	FOR(i, 1, 20)
		p2[i] = 2LL*p2[i - 1];

	set<LL> first, second;
	int MMM = n / 2;
	LL add;
	LL rto = 1 << MMM;
	FOR(i, 0, rto)
	{
		add = 0;
		FOR(j, 0, MMM)
			if (i & p2[j])
				add += a[j];

		first.insert(add%m);
	}

	int m1 = MMM;
	MMM = n - MMM;
	rto = (1 << MMM);
	FOR(i, 0, rto)
	{
		add = 0;
		FOR(j, 0, MMM)
			if (i & p2[j])
				add += a[j + m1];

		second.insert(add%m);
	}


	for (auto i : first)
		ans = max(ans, i);

	for (auto i : second)
		ans = max(ans, i);

	LL now;
	LL toMatch;
	VLL F(ALL(first));
	FOR(i, 0, SZ(F))
	{
		now = F[i];
		auto it = second.lower_bound(m - now);
		if (it != second.begin())
			--it;
		ans = max(ans, (now + *it) % m);
	}

	cout << ans << endl;
	cin >> n;
	return 0;
}