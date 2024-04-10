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

#define FOR(i,a,b) for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const int MAXN = 1e5 + 7;
const int MAXK = 31;

int n;
VI a;
VI b;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> n;
	a.resize(n);
	int delta = INF;
	FOR(i, 0, n)
		cin >> a[i], delta = min(delta, a[i]);

	FOR(i, 0, n)
		a[i] -= delta;

	sort(ALL(a));
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	FOR(i, 0, n)
		if (a[i] == 0)
			++cnt0;
		else
			if (a[i] == 1)
				++cnt1;
			else
				++cnt2;

	int mi = a[0], ma = a[n - 1];
	int di = ma - mi;
	
	if (di == 0)
	{
		cout << n << endl;
		FOR(i, 0, n)
			cout << delta << " ";

		cin >> n;
		return 0;
	}

	if (di == 1)
	{
		cout << n << endl;
		FOR(i, 0, cnt0)
			cout << delta << " ";
		FOR(i, 0, cnt1)
			cout << delta + 1 << " ";
		cin >> n;
		return 0;
	}

	int ans = 0;
	int cnt02 = min(cnt0, cnt2);

	int x = cnt02;
	int y = cnt1 / 2;
	int x0, x1, x2;
//	cout << x << " " << y << endl;
	if (x >= y)
	{
		int ch = x;
		x1 = cnt1 + ch*2;
		x2 = cnt2 - ch;
		x0 = cnt0 - ch;
	}
	else
	{
		int ch = y;
		x1 = cnt1 - ch * 2;
		x0 = cnt0 + ch;
		x2 = cnt2 + ch;				
	}

	FOR(i, 0, x0)
		b.push_back(0);

	FOR(i, 0, x1)
		b.push_back(1);

	FOR(i, 0, x2)
		b.push_back(2);

	ans = min(cnt0, x0);
	ans += min(cnt1, x1);
	ans += min(cnt2, x2);
	cout << ans << endl;
	FOR(i, 0, n)
		cout << b[i] + delta << " ";
	cin >> n;
	return 0;
}