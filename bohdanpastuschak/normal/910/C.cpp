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
const LL MAXN = 5e3 + 1;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	LL p10[10];
	p10[0] = 1;
	FOR(i, 1, 10)
		p10[i] = 10LL * p10[i - 1];

	vector<string> s(n);
	FOR(i, 0, n)
		cin >> s[i];

	VLL cnt(100, 0);
	FOR(i, 0, n)
	{
		FOR(j, 0, SZ(s[i]))
		{
			cnt[s[i][j] - 'a'] += p10[SZ(s[i]) - 1 - j];
		}
	}

	LL ans = LINF;
	VI num = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	VI ok(100, 1);
	FOR(i, 0, n)
		ok[s[i][0] - 'a'] = 0;

	do
	{
		if (ok[num[0]])
		{
			LL curr = 0;

			FOR(i, 1, 10)
				curr += i * cnt[num[i]];

			ans = min(ans, curr);

		}
	} while (next_permutation(ALL(num)));

	cout << ans;
	cin >> n;
	return 0;
}