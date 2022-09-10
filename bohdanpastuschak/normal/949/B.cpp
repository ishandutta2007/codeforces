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
const LL MAXN = 1e5 + 7;

void brute(LL n)
{
	int cnt_ok = n - 1;
	VI all(2 *n, 0);
	for (int i = 1; i <= n; ++i)
		all[2 * i - 1] = i;

	while(SZ(all) != n + 1)
	{
		int x = all.back();
		all.resize(SZ(all) - 1);
		if (x == 0)
			continue;

		all[2 * cnt_ok] = x;
		cnt_ok--;
	}

	for(int i = 2; i <= n; i += 2)
		cout << all[i] - (n + 1)/2 << " ";

	cout << endl;
}

inline LL solve(LL n, LL pos)
{
	if (n < 3)
		return pos;
	
	if (pos & 1)
		return 1 + pos / 2;

	LL i = pos / 2 ;
	return solve(n - i, n - i) + i;
}

inline LL wtf(LL n, LL pos)
{
	if (n & 1)
	{
		if (pos == 1)
			return solve((n - 1)/2, (n - 1)/2);
		else
			return solve((n - 1)/2, pos - 1);
	}
	else
		return solve(n/2, pos);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	LL n;
	cin >> n;

	//while (cin >> n)
		//brute(n);

	//	brute(n - 1);
		//brute(n);

	int q;
	cin >> q;
	LL x, ans;
	REP(Q, q)
	{
		cin >> x;
		if (x & 1)
		{
			ans = (x / 2) + 1;
			cout << ans << endl;
			continue;
		}

		ans = wtf(n, x / 2) + (n + 1) / 2;
		cout << ans << endl;
	}

	return 0;
}