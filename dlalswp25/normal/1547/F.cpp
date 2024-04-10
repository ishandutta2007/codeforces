#include <bits/stdc++.h>

using namespace std;

int N;
int A[262626];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

struct SegTree {
	int base;
	int T[525252];

	void init() {
		base = 1;
		while(base < N) base <<= 1;
		for(int i = base; i < base << 1; i++) T[i] = A[i - base];
		for(int i = base - 1; i >= 1; i--) T[i] = gcd(T[i << 1], T[i << 1 | 1]);
	}

	int get(int l, int r) {
		l += base; r += base;
		int ret = 0;
		while(l <= r) {
			if(l & 1) { ret = gcd(ret, T[l]); l++; }
			if(~r & 1) { ret = gcd(ret, T[r]); r--; }
			l >>= 1; r >>= 1;
		}
		return ret;
	}

	int query(int l, int r) {
		if(l <= r) return get(l, r);
		return gcd(get(0, r), get(l, N - 1));
	}
}seg;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int g = 0;
		for(int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			g = gcd(g, A[i]);
		}
		seg.init();
		int r = 0;
		int ans = 0;
		for(int i = 0; i < N; i++) {
			while(1) {
				if(seg.query(i, r) == g) break;
				r = (r + 1) % N;
			}
			if(i <= r) ans = max(ans, r - i);
			else ans = max(ans, r + N - i);
			if(i == r) r++;
		}
		printf("%d\n", ans);
	}
	return 0;
}