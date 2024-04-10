/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
const int N = 131072, L = 17;
int b[L][N];

pair <int, int> cnt (int l, int r, int x, int y) {
	if (l > r)
		return {0, -1};
	int sz = 1, wef = -1;
	while (sz <= (r - l + 1) && l % sz == 0)
		sz *= 2, wef++;
	sz /= 2;
	pair <int, int> p = cnt(l + sz, r, x, y);
	if (p.F >= 2)
		return p;
	auto aa = upper_bound(b[wef] + l, b[wef] + l + sz, y);
	auto bb = lower_bound(b[wef] + l, b[wef] + l + sz, x);
	int kk = aa - bb;
	if (kk != 0) {
		p.S = *(bb);
	}
	p.F += kk;
	return p;
}

inline void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", b[0] + i);
	}
	int n2 = 1;
	while (n2 < n)
		n2 *= 2;
	for (int i = n; i < n2; i++)
		b[0][i] = 0;
	n = n2;
	for (int i = 1; i < L; i++) {
		int wow = (1 << i);
		for (int j = 0; j < n; j += wow) {
			int in1 = j, in2 = (j + wow / 2);
			for (int k = 0; k < wow; k++) {
				bool f = false;
				if (in1 == (j + wow / 2))
					f = true;
				else if (in2 == (j + wow))
					f = false;
				else if (b[i - 1][in1] < b[i - 1][in2])
					f = false;
				else
					f = true;
				if (!f) {
					b[i][j + k] = b[i - 1][in1];
					in1++;
				} else {
					b[i][j + k] = b[i - 1][in2];
					in2++;
				}
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int x = 0, o;
		vector <int> v;
		for (int i = 29; i >= 0; i--) {
			o = 0;
			vector <int> v2;
			for (int j : v) {
				if (!(j & (1 << i)))
					o++, v2.push_back(j);
			}
			int a = x, b = x + (1 << i) - 1;
			pair <int, int> p = cnt(l, r, a, b);
			int ans = p.F;
			if (ans + o >= 2) {
				v = v2;
				continue;
			}
			x += (1 << i);
			if (ans == 1) 
				v.push_back(p.S);
		}
		printf("%d ", x);
	}
}

int32_t main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}