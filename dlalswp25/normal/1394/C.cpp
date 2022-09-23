#include <bits/stdc++.h>

using namespace std;

const int base = 524288;

struct SEG_min {
	int T[1050505];

	void init() {
		for(int i = 0; i < 1050505; i++) T[i] = 1010101010;
	}

	void upd(int p, int q, int x) {
		p = max(p, 0);
		q = min(q, 500000);
		int l = base + p;
		int r = base + q;
		while(l <= r) {
			if(l & 1) { T[l] = min(T[l], x); l++; }
			if(~r & 1) { T[r] = min(T[r], x); r--; }
			l >>= 1; r >>= 1;
		}
	}

	int get(int p) {
		int ret = 1010101010;
		p = base + p;
		while(p) {
			ret = min(ret, T[p]);
			p >>= 1;
		}
		return ret;
	}
}mn0, mn1;

struct SEG_max {
	int T[1050505];

	void init() {
		for(int i = 0; i < 1050505; i++) T[i] = -1010101010;
	}

	void upd(int p, int q, int x) {
		p = max(p, 0);
		q = min(q, 500000);
		int l = base + p;
		int r = base + q;
		while(l <= r) {
			if(l & 1) { T[l] = max(T[l], x); l++; }
			if(~r & 1) { T[r] = max(T[r], x); r--; }
			l >>= 1; r >>= 1;
		}
	}

	int get(int p) {
		int ret = -1010101010;
		p = base + p;
		while(p) {
			ret = max(ret, T[p]);
			p >>= 1;
		}
		return ret;
	}
}mx0, mx1;

int N;
int X[303030];
int Y[303030];
char S[505050];

int A, B;

bool solve(int x) {
	mn0.init(); mn1.init();
	mx0.init(); mx1.init();

	// printf("%d\n", x);

	int lx = 0, rx = 500000;
	for(int i = 1; i <= N; i++) {
		mn0.upd(X[i], X[i] + x, Y[i] + x);
		// printf("mn0 upd %d %d %d\n", X[i], X[i] + x, Y[i] + x);
		mn1.upd(X[i] - x, X[i], Y[i] + x - X[i]);
		// printf("mn1 upd %d %d %d\n", X[i] - x, X[i], Y[i] + x - X[i]);
		mx0.upd(X[i] - x, X[i], Y[i] - x);
		// printf("mx0 upd %d %d %d\n", X[i] - x, X[i], Y[i] - x);
		mx1.upd(X[i], X[i] + x, Y[i] - x - X[i]);
		// printf("mx1 upd %d %d %d\n", X[i], X[i] + x, Y[i] - x - X[i]);
		lx = max(lx, X[i] - x);
		rx = min(rx, X[i] + x);
	}

	if(lx > rx) return false;

	for(int i = lx; i <= rx; i++) {
		int up = min(mn0.get(i), mn1.get(i) + i);
		int dn = max(mx0.get(i), mx1.get(i) + i);
		// printf("i = %d, mx1 : %d\n", i, mx1.get(i));

		// printf("%d %d %d\n", i, up, dn);
		if(up >= dn && max(i, up) > 0) {
			A = i; B = up;
			// printf("upd : %d %d\n", i, up);
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%s", S + 1);
		int M = strlen(S + 1);
		for(int j = 1; j <= M; j++) {
			if(S[j] == 'B') X[i]++;
			else Y[i]++;
		}
	}

	// for(int i = 1; i <= N; i++) printf("%d %d\n", X[i], Y[i]); puts("");

	int l = 0, r = 500000;

	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) r = m - 1;
		else l = m + 1;
	}

	solve(l);
	printf("%d\n", l);
	for(int i = 1; i <= A; i++) printf("B");
	for(int i = 1; i <= B; i++) printf("N");
	puts("");

	return 0;
}