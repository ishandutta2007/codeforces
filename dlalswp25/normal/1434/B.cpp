#include <bits/stdc++.h>

using namespace std;

int N;
int ans[101010];
int p[101010];

struct SEG {
	int T[262626];
	int base = 131072;

	void upd(int p, int x) {
		p += base; p--;
		T[p] = x;
		while(p > 1) {
			p >>= 1;
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}

	int get(int p, int q) {
		p += base; q += base;
		p--; q--;
		int ret = 0;
		while(p <= q) {
			if(p & 1) { ret = max(ret, T[p]); p++; }
			if(~q & 1) { ret = max(ret, T[q]); q--; }
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}seg;

int par(int x) {
	if(p[x] == x) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return;
	if(a > b) swap(a, b);
	p[a] = b;
}

int main() {
	scanf("%d", &N);
	int pos = 0;
	for(int i = 1; i <= N + 1; i++) p[i] = i;

	for(int i = 1; i <= 2 * N; i++) {
		char c; scanf(" %c", &c);
		if(c == '+') pos++;
		else {
			int x; scanf("%d", &x);
			int t = seg.get(x + 1, N) + 1;
			t = par(t);
			if(t > pos) { puts("NO"); return 0; }
			ans[t] = x;
			unite(t, t + 1);
			seg.upd(x, pos);
		}
	}

	puts("YES");
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");

	return 0;
}