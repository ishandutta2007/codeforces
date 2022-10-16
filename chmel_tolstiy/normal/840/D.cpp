#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

const int nn = 310000;

struct query {
	int l, r, id;
};

int K;

struct data {
	int a[5], b[5], cnt;
	data() : cnt(0) {}

	void add(int x, int y) {
		for (int i = 0; i < cnt; ++i) if (a[i] == x) { b[i] += y; return; }
		a[cnt] = x; b[cnt] = y; ++cnt;
		if (cnt > K) {
			int z = b[0]; for (int i = 1; i < cnt; ++i) z = min(z, b[i]);
			for (int i = 0; i < cnt; ++i) b[i] -= z;
		}
		int _n = 0;
		for (int i = 0; i < cnt; ++i) if (b[i] > 0) {
			a[_n] = a[i]; b[_n] = b[i]; ++_n;
		}
		cnt = _n;
	}

	void combine(const data& a) {
		for (int t = 0; t < a.cnt; ++t) {
			int x = a.a[t], y = a.b[t];
			add(x, y);
		}
	}
};

vector<int> pos[nn];

int fr(int x, int l, int r) {
	return upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l);
}

vector<data> S;
int N;

void init(int n) {
	N = 1;
	while (N < n) N *= 2;
	S.assign(N * 2, data());
}

void add(int pos, int val) {
	pos += N;
	data& d = S[pos];
	d.add(val, 1);
	while (pos > 1) {
		pos /= 2;
		S[pos] = S[pos * 2];
		S[pos].combine(S[pos * 2 + 1]);
	}
}

data get(int L, int R) {
	L += N;
	R += N;
	data result;
	while (L < R) {
		if ((L & 1) == 1) { result.combine(S[L]); ++L; }
		if ((R & 1) == 0 && L < R) { result.combine(S[R]); --R; }
		if (L != R) {
			L /= 2;
			R /= 2;
		}
	}
	if (L == R)
		result.combine(S[L]);
	return result;
}

bool solve() {
	int n, q; cin >> n >> q;

	vector<query> Q[5];
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < q; ++i) {
		int k;
		query qq; cin >> qq.l >> qq.r >> k; qq.id = i;
		--qq.l; --qq.r;
		Q[k - 1].push_back(qq);
	}

	for (int i = 0; i < n; ++i) pos[a[i]].push_back(i);

	vector<int> ans(q, -1);
	for (K = 1; K <= 4; ++K) {
		init(n);
		for (int i = 0; i < n; ++i) add(i, a[i]);

		for (int i = 0; i < Q[K].size(); ++i) {
			data z = get(Q[K][i].l, Q[K][i].r);
			int res = n + 1;
			int L  = (Q[K][i].r - Q[K][i].l + 1);
			for (int j = 0; j < z.cnt; ++j) 
				if (fr(z.a[j], Q[K][i].l, Q[K][i].r) * (K + 1) > L)
					res = min(res, z.a[j]);
			if (res <= n)
				ans[Q[K][i].id] = res;
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}

	return false;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

    while (solve());
    
    return 0;
}