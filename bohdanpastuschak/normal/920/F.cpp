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
typedef unsigned long long LL;
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
const LD EPS = 1e-9;
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e15;
const LL MAX = 3e5 + 7;
const LL MAXN = 1e6 + 1;

int n;
int m;
int a[MAX];
int d[MAXN];
int CNT[MAX];
int to_er[MAX];
LL tree[4 * MAX];
set<int> ne_dva;

inline void build(int v, int tl, int tr)
{
	if (tl == tr)
		tree[v] = a[tl];
	else
	{
		int tm = (tl + tr) >> 1;
		build(v << 1, tl, tm);
		build((v << 1) + 1, tm + 1, tr);
		tree[v] = tree[v << 1] + tree[(v << 1) + 1];
	}
}

inline LL sum(int v, int tl, int tr, int l, int r)
{
	if (l > tr || tl > r)
		return 0;

	if (tl == l && r == tr)
		return tree[v];

	int tm = (tl + tr) >> 1;
	return sum(v << 1, tl, tm, l, min(tm, r)) + sum((v << 1) + 1, tm + 1, tr, max(tm + 1, l), r);
}

inline void update(int v, int tl, int tr, int pos, int val)
{
	if (pos < tl || pos > tr)
		return;

	if (tl == tr)
		tree[v] = val;
	else
	{
		int tm = (tl + tr) >> 1;
		update(v << 1, tl, tm, pos, val);
		update((v << 1) + 1, tm + 1, tr, pos, val);

		tree[v] = tree[v << 1] + tree[(v << 1) + 1];
	}
}

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	FOR(i, 1, MAXN)
		for (int j = i; j < MAXN; j += i)
			d[j]++;

	scanf("%d %d", &n, &m);// cin >> n >> m;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);// cin >> a[i];
		ne_dva.insert(i); 
	}

	build(1, 0, n - 1);
	int l, r, t;
	int cnt = 0;
	FOR(i, 0, m)
	{
		scanf("%d %d %d", &t, &l, &r);// cin >> t >> l >> r;
		--l; --r;
		if (t == 1)
		{
			int x;
			for (auto it = ne_dva.lower_bound(l); it != ne_dva.end() && *it <= r; ++it)
			{
				x = *it;
				CNT[x]++;
				if (CNT[x] > 6)
					to_er[cnt++] = x;

				a[x] = d[a[x]];
				update(1, 0, n - 1, x, a[x]);
			}

			FOR(j, 0, cnt)
				ne_dva.erase(to_er[j]);

			cnt = 0;
		}
		else
			printf("%lld \n", sum(1, 0, n - 1, l, r));
	}

	//cin >> n;
	return 0;
}