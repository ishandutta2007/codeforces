#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <bitset>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

#define SZ(a) (LL)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define MP make_pair
#define X first
#define Y second
#define next fake_next
#define left fake_left
#define right fake_right
#define delete fake_delete
const LD PI = acos(-1.0);
const LL MAXN = 1e6;
const LL mod = 1000000007;
const LL INF = 1e9;

LL n;
VLL a;

void solve(LL k)
{
	if (k == 0)
	{
		a[0] = 0;
		return;
	}
	if (k == 1)
	{
		a[0] = 1;
		a[1] = 0;
		return;
	}

	int b = 0;
	while ((1 << b) <= k)
		++b;

	VI x(1 << b, 0);
	FOR(i, 0, (1 << b))
		x[i] = (1 << b) - i - 1;

	int to = -1;
	FOR(i, 0, k + 1)
		if (x[i] <= k)
			a[i] = x[i];
		else
			to = i;

	if (to != -1)
		solve(to);
}

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	cout << n*(n + 1) << endl;

	a.assign(n + 1, 0);

	solve(n);
	FOR(i, 0, n + 1)
		cout << a[i] << " ";
	cin >> n;
	return 0;
}