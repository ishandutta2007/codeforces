#include <bits/stdc++.h>

using namespace std;

int N, M, Q;

struct SegTree {
	int T[4 * 202020];
	int base;

	void init(int n) {
		for(base = 1; base < n; base <<= 1);
		for(int i = 1; i < base + base; i++) T[i] = 0;
	}

	void upd(int p, int x) {
		p += base; p--;
		T[p] = x;
		while(p > 1) {
			p >>= 1;
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}

	int get(int p, int q) {
		if(p > q) return 0;
		p += base; q += base;
		p--; q--;
		int ret = 0;
		while(p <= q) {
			if(p & 1) ret = max(ret, T[p++]);
			if(~q & 1) ret = max(ret, T[q--]);
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}seg;

int main() {
	scanf("%d%d", &N, &M);
	seg.init(M);
	for(int i = 1; i <= M; i++) {
		int a; scanf("%d", &a);
		seg.upd(i, a);
	}
	scanf("%d", &Q);
	while(Q--) {
		int x1, y1, x2, y2, k; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
		if(x1 % k != x2 % k || y1 % k != y2 % k) { puts("NO"); continue; }
		if(y1 > y2) swap(y1, y2);
		int t = (N / k) * k;
		int x = t + x1 % k; if(x > N) x -= k;
		puts(seg.get(y1 + 1, y2 - 1) >= x ? "NO" : "YES");
	}
	return 0;
}