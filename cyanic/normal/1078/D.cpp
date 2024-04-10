#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

template <class T> inline void read(T &x) {
	char ch = getchar(); int op = 0; x = 0;
	while (!isdigit(ch)) op |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	if (op) x = - x;
}

const int N = 300005;
int x[N], l[20][N], r[20][N];
int n, m;

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
struct ST {
	int mn[N << 2], mx[N << 2];
	void build(int o, int l, int r, int L[N], int R[N]) {
		if (l == r) {
			mn[o] = L[l], mx[o] = R[l];
			return;
		}
		build(lc, l, mid, L, R);
		build(rc, mid + 1, r, L, R);
		mn[o] = min(mn[lc], mn[rc]);
		mx[o] = max(mx[lc], mx[rc]);
	}
	int qmin(int o, int l, int r, int x, int y) {
		if (l == x && y == r) return mn[o];
		if (y <= mid) return qmin(lc, l, mid, x, y);
		if (mid < x) return qmin(rc, mid + 1, r, x, y);
		return min(qmin(lc, l, mid, x, mid),
				   qmin(rc, mid + 1, r, mid + 1, y));
	}
	int qmax(int o, int l, int r, int x, int y) {
		if (l == x && y == r) return mx[o];
		if (y <= mid) return qmax(lc, l, mid, x, y);
		if (mid < x) return qmax(rc, mid + 1, r, x, y);
		return max(qmax(lc, l, mid, x, mid),	
				   qmax(rc, mid + 1, r, mid + 1, y));
	}
} T[20];

void doit(int s) {
	int l = s, r = s, res = 0, L, R;
	per (i, 18, 0) {
		L = T[i].qmin(1, 1, m, l, r);
		R = T[i].qmax(1, 1, m, l, r);
		if (R - L + 1 < n) {
			l = L, r = R;
			res |= 1 << i;
		}
	}
	printf("%d ", res + 1);
}

int main() {
	read(n);
	if (n == 1) return puts("0"), 0;
	rep (i, 1, n) {
		read(x[i]);
		x[i + n] = x[i + n + n] = x[i];
	}
	m = 3 * n;
	rep (i, 1, m) {
		l[0][i] = max(1, i - x[i]);
		r[0][i] = min(m, i + x[i]);
	}
	T[0].build(1, 1, m, l[0], r[0]);
	rep (j, 1, 18) {
		rep (i, 1, m) {
			l[j][i] = T[j - 1].qmin(1, 1, m, l[j - 1][i], r[j - 1][i]);
			r[j][i] = T[j - 1].qmax(1, 1, m, l[j - 1][i], r[j - 1][i]);
		}
		T[j].build(1, 1, m, l[j], r[j]);
	}
	rep (i, n + 1, n + n) doit(i);
	return 0;
}