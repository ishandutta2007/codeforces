#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int a[maxn], b;
struct Fenwick {
	int sum[maxn << 2];
	bool fg[maxn << 2];

#define LCH o+o, l, m
#define RCH o+o+1, m+1, r

	void build(int o, int l, int r) {
		if(l == r) {
			sum[o] = (a[l] & b) ? 1 : 0;
			fg[o] = false;
			return ;
		}
		int m = (l + r) >> 1;
		build(LCH);
		build(RCH);
		sum[o] = sum[o+o] + sum[o+o+1];
		fg[o] = false;
	}
	void f(int o, int l, int r) {
		fg[o] = !fg[o];
		sum[o] = (r - l + 1) - sum[o];
	}
	void pd(int o, int l, int r) {
		if(!fg[o]) return ;
		int m = (l + r) >> 1;
		f(LCH);
		f(RCH);
		fg[o] = false;
	}
	void update(int o, int l, int r, int ql, int qr) {
		if(ql <= l and r <= qr) {
			fg[o] = !fg[o];
			sum[o] = (r - l + 1) - sum[o];
			return ;
		}
		int m = (l + r) >> 1;
		pd(o, l, r);
		if(ql <= m) update(LCH, ql, qr);
		if(qr > m) update(RCH, ql, qr);
		sum[o] = sum[o+o] + sum[o+o+1];
	}
	int query(int o, int l, int r, int ql, int qr) {
		if(ql <= l and r <= qr) {
			return sum[o];
		}
		int ret = 0;
		int m = (l + r) >> 1;
		pd(o, l, r);
		if(ql <= m) ret += query(LCH, ql, qr);
		if(qr > m) ret += query(RCH, ql, qr);
		return ret;
	}
} seg[20];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	b = 1;
	for(int i = 0; i < 20; ++i) {
		seg[i].build(1, 1, n);
		b <<= 1;
	}
	int m;
	scanf("%d", &m);
	int op, lb, rb, v;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &op, &lb, &rb);
		if(op == 2) {
			scanf("%d", &v);
			b = 1;
			for(int i = 0; i < 20; ++i) {
				if(v & b) seg[i].update(1, 1, n, lb, rb);
				b <<= 1;
			}
		}
		else {
			b = 1;
			long long ans = 0;
			for(int i = 0; i < 20; ++i, b <<= 1) {
				ans += 1LL * b * seg[i].query(1, 1, n, lb, rb);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}