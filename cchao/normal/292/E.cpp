#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int a[maxn], b[maxn], x, y, k;
struct Seg {
	int fg[maxn << 2];

#define LCH o+o, l, m
#define RCH o+o+1, m+1, r

	void build(int o, int l, int r) {
		fg[o] = 0;
		if(l == r) {
			return ;
		}
		int m = (l + r) >> 1;
		build(LCH);
		build(RCH);
	}
	void f(int o, int l, int r, int v) {
		fg[o] = v;
	}
	void pd(int o, int l, int r) {
		if(!fg[o]) return ;
		int m = (l + r) >> 1;
		f(LCH, fg[o]);
		f(RCH, fg[o] + (m - l) + 1);
		fg[o] = 0;
	}
	void update(int o, int l, int r, int ql, int qr) {
		if(ql <= l and r <= qr) {
			fg[o] = x + (l - y);
			return ;
		}
		int m = (l + r) >> 1;
		pd(o, l, r);
		if(ql <= m) update(LCH, ql, qr);
		if(qr > m) update(RCH, ql, qr);
	}
	int query(int o, int l, int r, int qv) {
		if(l == r) {
			return fg[o] ? a[fg[o]] : b[l];
		}
		int m = (l + r) >> 1;
		pd(o, l, r);
		if(qv <= m) return query(LCH, qv);
		else return query(RCH, qv);
	}
} seg;

int main() {
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	seg.build(1, 1, n);
	int op, v;
	for(int i = 0; i < m; ++i) {
		scanf("%d", &op);
		if(op == 2) {
			scanf("%d", &v);
			printf("%d\n", seg.query(1, 1, n, v));
		}
		else {
			scanf("%d%d%d", &x, &y, &k);
			seg.update(1, 1, n, y, y + k - 1);
		}
	}
	return 0;
}