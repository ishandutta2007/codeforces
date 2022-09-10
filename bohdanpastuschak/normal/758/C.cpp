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

#define FOR(i,a,b) for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL MAXN = 1e5 + 1;
const LD EPS = 1e-6;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	LL n, m, k, x, y;
	cin >> n >> m >> k >> x >> y;
	--x;
	--y;
	LL circle = 2 * (n - 1)*m;
	if (n == 1)
		circle = m;

	LL full = k / circle;
	k %= circle;

	VVLL ans(n, VLL(m, full));
	
	FOR(i, 1, n - 1)
		FOR(j, 0, m)
		ans[i][j] *= 2;

	FOR(i,0,n)
		FOR(j,0,m)
		if (k)
		{
			--k;
			++ans[i][j];
		}

	RFOR(i, n - 1, 0)
		FOR(j, 0, m)
		if (k)
		{
			--k;
			++ans[i][j];
		}


	VLL all;
	FOR(i, 0, n)
		FOR(j, 0, m)
		all.push_back(ans[i][j]);

	sort(ALL(all));
	cout << all.back() << " " << all[0] << " " << ans[x][y] << endl;
	return 0;
}