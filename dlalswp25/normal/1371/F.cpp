#include <bits/stdc++.h>

using namespace std;

int N, Q;

char A[505050];

struct NODE {
	int pref[2];
	int suf[2];
	int mx[2];
	int lft[2];
	int rgt[2];
	int len;
	int lz;

	NODE() : len(0), lz(0) {
		for(int i = 0; i < 2; i++) {
			pref[i] = suf[i] = mx[i] = lft[i] = rgt[i] = 0;
		}
	}

	void print() {
		printf("pref : %d %d\n", pref[0], pref[1]);
		printf("suf : %d %d\n", suf[0], suf[1]);
		printf("mx : %d %d\n", mx[0], mx[1]);
		printf("lft : %d %d\n", lft[0], lft[1]);
		printf("rgt : %d %d\n", rgt[0], rgt[1]);
		printf("len : %d\n", len);
		printf("lz : %d\n", lz);
		puts("");
	}
};

NODE merge(NODE l, NODE r) {
	NODE ret;
	for(int i = 0; i < 2; i++) {
		ret.mx[i] = max(l.mx[i], r.mx[i]);
		ret.mx[i] = max(ret.mx[i], max(l.suf[i] + r.lft[i], l.rgt[i] + r.pref[i]));
		ret.mx[i] = max(ret.mx[i], max(ret.pref[i], ret.suf[i]));
		ret.lft[i] = (l.lft[i] == l.len ? l.lft[i] + r.lft[i] : l.lft[i]);
		ret.rgt[i] = (r.rgt[i] == r.len ? r.rgt[i] + l.rgt[i] : r.rgt[i]);

		if(l.pref[i] == l.len) ret.pref[i] = (l.rgt[i] == l.len ? l.rgt[i] + r.pref[i] : l.pref[i] + r.lft[i]);
		else ret.pref[i] = l.pref[i];
		if(r.suf[i] == r.len) ret.suf[i] = (r.lft[i] == r.len ? r.lft[i] + l.suf[i] : r.suf[i] + l.rgt[i]);
		else ret.suf[i] = r.suf[i];
	}
	ret.len = l.len + r.len;
	return ret;
}

struct SEG {
	NODE T[4 * 505050];

	void init(int idx, int s, int e, int p) {
		if(p < s || e < p) return;
		if(s == e) {
			T[idx].len = 1;
			T[idx].pref[0] = T[idx].pref[1] = 1;
			T[idx].suf[0] = T[idx].suf[1] = 1;
			T[idx].mx[0] = T[idx].mx[1] = 1;
			if(A[s] == '<') {
				T[idx].lft[0] = 1;
				T[idx].rgt[1] = 1;
			}
			else {
				T[idx].rgt[0] = 1;
				T[idx].lft[1] = 1;
			}
			return;
		}
		int m = s + e >> 1;
		init(idx << 1, s, m, p);
		init(idx << 1 | 1, m + 1, e, p);
		T[idx] = merge(T[idx << 1], T[idx << 1 | 1]);
	}

	void propa(int idx, int s, int e) {
		if(T[idx].lz) {
			swap(T[idx].pref[0], T[idx].pref[1]);
			swap(T[idx].suf[0], T[idx].suf[1]);
			swap(T[idx].mx[0], T[idx].mx[1]);
			swap(T[idx].lft[0], T[idx].lft[1]);
			swap(T[idx].rgt[0], T[idx].rgt[1]);

			if(s != e) {
				T[idx << 1].lz = 1 - T[idx << 1].lz;
				T[idx << 1 | 1].lz = 1 - T[idx << 1 | 1].lz;
			}
			T[idx].lz = 0;
		}
	}

	void upd(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz = 1 - T[idx].lz;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q);
		upd(idx << 1 | 1, m + 1, e, p, q);
		T[idx] = merge(T[idx << 1], T[idx << 1 | 1]);
	}

	NODE get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return NODE();
		if(p <= s && e <= q) return T[idx];
		int m = s + e >> 1;
		return merge(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}

	void print_tree(int idx, int s, int e) {
		printf("idx = %d / [%d %d]\n", idx, s, e);
		T[idx].print();
		if(s == e) return;
		int m = s + e >> 1;
		print_tree(idx << 1, s, m);
		print_tree(idx << 1 | 1, m + 1, e);
	}
}seg;

int main() {
	scanf("%d%d", &N, &Q);
	scanf("%s", A + 1);
	for(int i = 1; i <= N; i++) seg.init(1, 1, N, i);
	// seg.print_tree(1, 1, N);

	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		seg.upd(1, 1, N, l, r);
		// seg.print_tree(1, 1, N);
		printf("%d\n", seg.get(1, 1, N, l, r).mx[0]);
	}

	return 0;
}