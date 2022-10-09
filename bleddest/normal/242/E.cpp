#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <queue>
#include <map>

#define li long long
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define all(a) a.begin(), a.end()

using namespace std;

inline void boost() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

const double pi = acos(-1);
const long long INF = 1e17 + 13;
const int N = 20;

struct node {
	//bool needUpd;

	int cnt[N];
	int later[N];
};

li n;
vector<li> a;
vector<node> t;

inline void build(li v, li tl, li tr) {
	//t[v].needUpd = false;

	if (tl == tr) {
		for (int i = 0; i < N; i++) {
			t[v].later[i] = 0;
			t[v].cnt[i] = a[tl] % 2;
			a[tl] /= 2;
		}
	}
	else {
		li tm = (tl + tr) / 2;
		build(2 * v + 1, tl, tm);
		build(2 * v + 2, tm + 1, tr);

		for (int i = 0; i < N; i++) {
			t[v].later[i] = 0;
			t[v].cnt[i] = t[2 * v + 1].cnt[i] + t[2 * v + 2].cnt[i];
		}
	}
}

inline void apply(li v, li l, li r, int x[N])
{
	for (int i = 0; i < N; i++) {
		t[v].later[i] ^= x[i];
		if (x[i]) {
			t[v].cnt[i] = r - l + 1 - t[v].cnt[i];
		}
	}
}

inline void push(li v, li l, li r) {
	li m = (l + r) / 2;
	if (l != r) {
		apply(2 * v + 1, l, m, t[v].later);
		apply(2 * v + 2, m + 1, r, t[v].later);
	}

	for (int i = 0; i < N; i++) {
		t[v].later[i] = 0;
		//t[v].needUpd = false;
	}
}

inline void update(li v, li tl, li tr, li l, li r, int x[N]) {
	if (l > r) {
		return;
	}

	if (tl == l && tr == r) {
		apply(v, l, r, x);
	}
	else {
		push(v, tl, tr);

		li tm = (tl + tr) / 2;
		update(2 * v + 1, tl, tm, l, min(tm, r), x);
		update(2 * v + 2, tm + 1, tr, max(tm + 1, l), r, x);

		for (int i = 0; i < N; i++) {
			t[v].cnt[i] = t[2 * v + 1].cnt[i] + t[2 * v + 2].cnt[i];
		}
	}
}

inline li getSum(li v, li tl, li tr, li l, li r) {
	if (l > r) {
		return 0;
	}

	if (tl == l && tr == r) {
		li res = 0, carry = 1;
		for (int i = 0; i < N; i++) {
			int curCnt = t[v].cnt[i];

			res += carry * curCnt;
			carry *= 2;
		}

		return res;
	}
	else {
		push(v, tl, tr);

		li tm = (tl + tr) / 2;
		li res = getSum(2 * v + 1, tl, tm, l, min(tm, r)) + getSum(2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
		return res;
	}
}

int main() {

	cin >> n;
	a.resize(n);
	t.resize(4 * n);
	for (li i = 0; i < n; i++) {
		cin >> a[i];
	}

	build(0, 0, n - 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int reqType;
		li l, r;
		cin >> reqType >> l >> r;
		l--, r--;

		if (reqType == 1) {
			cout << getSum(0, 0, n - 1, l, r) << endl;
		}
		else {
			li x;
			cin >> x;
			int xr[N];
			for (int i = 0; i < 20; i++) {
				xr[i] = x % 2;
				x /= 2;
			}

			update(0, 0, n - 1, l, r, xr);
		}
	}

	return 0;
}