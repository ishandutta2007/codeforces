#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[303030];
int cnt[303030];
int bef[303030];

int ans[303030];
int rgt[303030];
int id;

struct FWT {
	int T[303030];

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}

	int ge(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int get(int l, int r) {
		return ge(r) - ge(l - 1);
	}
}fwt;

struct NODE {
	int l, r, x;
	NODE() : l(0), r(0), x(0) {}
};

NODE T[20 * 303030];
int rt[303030];

int maketree(int bef, int s, int e, int p) {
	if(e < s || p < s || e < p) return bef;

	int now = ++id;

	if(s == e) {
		T[now].x = T[bef].x + 1;
		return now;
	}
	int m = s + e >> 1;
	T[now].l = maketree(T[bef].l, s, m, p);
	T[now].r = maketree(T[bef].r, m + 1, e, p);
	T[now].x = T[T[now].l].x + T[T[now].r].x;
	return now;
}

int get(int now, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[now].x;
	int m = s + e >> 1;
	return get(T[now].l, s, m, p, q) + get(T[now].r, m + 1, e, p, q);
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) ans[i] = i;

	for(int i = 1; i <= M; i++) {
		if(bef[A[i]]) rgt[bef[A[i]]] = i;
		bef[A[i]] = i;
	}
	for(int i = 1; i <= M; i++) if(!rgt[i]) rgt[i] = M + 1;

	for(int i = 1; i <= M; i++) rt[i] = maketree(rt[i - 1], 1, M + 1, rgt[i]);

	for(int i = 1; i <= N; i++) bef[i] = 0;

	for(int i = 1; i <= M; i++) {
		int j = A[i];
		if(!cnt[j]) {
			ans[j] = max(ans[j], (j - 1) + fwt.get(j + 1, N) + 1);
			fwt.upd(j, 1);
		}
		else {
			ans[j] = max(ans[j], get(rt[i - 1], 1, M + 1, i, M + 1) - get(rt[bef[j]], 1, M + 1, i, M + 1) + 1);
		}
		bef[j] = i;
		cnt[j]++;
	}

	for(int i = 1; i <= N; i++) {
		if(bef[i]) ans[i] = max(ans[i], get(rt[M], 1, M + 1, M + 1, M + 1) - get(rt[bef[i]], 1, M + 1, M + 1, M + 1) + 1);
		else {
			ans[i] = max(ans[i], i + fwt.get(i + 1, N));
		}
	}

	for(int i = 1; i <= N; i++) {
		if(!cnt[i]) printf("%d ", i);
		else printf("1 ");
		printf("%d\n", ans[i]);
	}

	return 0;
}