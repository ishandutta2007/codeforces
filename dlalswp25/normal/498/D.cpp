#include <bits/stdc++.h>

using namespace std;

struct NODE {
	int v[66];
}T[4 * 101010];

int A[101010];

int N, Q;

void update(int idx, int s, int e, int p, int x) {
	if(e < s || p < s || e < p) return;
	if(s == e) {
		for(int i = 0; i < 60; i++) {
			if(i % x == 0) T[idx].v[i] = 2;
			else T[idx].v[i] = 1;
		}
		return;
	}
	int m = s + e >> 1;
	update(idx * 2, s, m, p, x);
	update(idx * 2 + 1, m + 1, e, p, x);

	for(int i = 0; i < 60; i++) {
		int j = (i + T[idx * 2].v[i]) % 60;
		T[idx].v[i] = T[idx * 2].v[i] + T[idx * 2 + 1].v[j];
	}
}

int get(int idx, int s, int e, int p, int q, int t) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[idx].v[t];
	int m = s + e >> 1;
	int t1 = get(idx * 2, s, m, p, q, t);
	return t1 + get(idx * 2 + 1, m + 1, e, p, q, (t + t1) % 60);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		update(1, 1, N, i, a);
	}
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) {
		char c; scanf(" %c", &c);
		if(c == 'A') {
			int l, r; scanf("%d%d", &l, &r);
			r--;
			printf("%d\n", get(1, 1, N, l, r, 0));
		}
		else {
			int x, y; scanf("%d%d", &x, &y);
			update(1, 1, N, x, y);
		}
	}
	return 0;
}