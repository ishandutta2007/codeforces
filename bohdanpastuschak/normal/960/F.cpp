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
#include <bitset>
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e5 + 47;

struct tree
{
	VI t;

	int get_max(int v, int tl, int tr, int l, int r) {
		if (l > r)
			return 0;
		if (l == tl && r == tr)
			return t[v];
		int tm = (tl + tr) >> 1;
		return max(
			get_max(v << 1, tl, tm, l, min(r, tm)),
			get_max(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
	}

	void update(int v, int tl, int tr, int pos, int new_val)
	{
		if (tl == tr)
			t[v] = new_val;
		else
		{
			int tm = (tl + tr) >> 1;
			if (pos <= tm)
				update(v <<1, tl, tm, pos, new_val);
			else
				update(v + v + 1, tm + 1, tr, pos, new_val);
			t[v] = max(t[v <<1], t[v + v + 1]);
		}
	}
};

int n;
int m;
pair<int, PII> e[MAX];
vector<PII> go[MAX];

tree seg[MAX];
map<PII, int> cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m;
	int u, v, w;
	FOR(i, 0, m)
	{
		cin >> u >> v >> w;
		--u; --v;
		e[i] = MP(w, MP(u, v));
		go[v].push_back(MP(w, u));
	}

	FOR(i, 0, n)
	{
		seg[i].t.assign(4 * SZ(go[i]), 0);
		sort(ALL(go[i]));
	}

	int ans = 0;
	int curr;
	FOR(i, 0, m)
	{
		w = e[i].X;
		u = e[i].Y.X;
		v = e[i].Y.Y;

		curr = 1;
		int pos = upper_bound(ALL(go[u]), MP(w, -1)) - go[u].begin();

		curr = max(curr, 1 + seg[u].get_max(1, 0, SZ(go[u]) - 1, 0, pos - 1));

		ans = max(ans, curr);
		pos = lower_bound(ALL(go[v]), MP(w, u)) - go[v].begin() + cnt[v][MP(w, u)];
		cnt[v][MP(w, u)]++;
		seg[v].update(1, 0, SZ(go[v]) - 1, pos, curr);
	}

	cout << ans << endl;
	cin >> n;
	return 0;
}