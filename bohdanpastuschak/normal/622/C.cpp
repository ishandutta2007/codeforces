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
#define SZ(a) (LL)((a).size())

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e9;
const LL MAX = 2e5 + 7;
const LL MAXN = 1e6 + 1;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	VI a(n);
	FOR(i, 0, n)
		cin >> a[i];

	VI next(n, -1);
	int curr = 0;
	VI t;
	while (curr < n - 1)
	{
		int now = curr;
		if (a[curr] != a[curr + 1])
		{
			next[curr] = curr + 1;
			++curr;
			continue;
		}

		t.clear();
		t.push_back(curr);
		++curr;
		while (curr < n && a[curr] == a[curr - 1])
			t.push_back(curr++);

		if (curr != n)
		{
			for (auto i : t)
				next[i] = curr;
		}
	}

	int l, r, x;
	FOR(i, 0, m)
	{
		cin >> l >> r >> x;
		--l, --r;
		if (a[l] != x)
		{
			cout << l + 1 << endl;
			continue;
		}

		if (next[l] == -1 || next[l] > r)
			cout << -1 << endl;
		else
			cout << next[l] + 1 << endl;
	}

	return 0;
}