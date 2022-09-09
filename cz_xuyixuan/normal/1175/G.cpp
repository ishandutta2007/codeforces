#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct point {int x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
struct SegmentTreeQ {
	struct Node {
		int lc, rc;
		vector <point> a;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r, int *y) {
		root = ++size;
		vector <point> &s = a[root].a; s.clear();
		for (int i = l; i <= r; i++) {
			point cur = (point) {i, y[i]};
			while (s.size() >= 2 && (cur - s.back()) * (s.back() - s[s.size() - 2]) >= 0) s.pop_back();
			s.push_back(cur);
		}
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, y);
		build(a[root].rc, mid + 1, r, y);
	}
	void init(int x, int *y) {
		n = x, root = size = 0;
		build(root, 0, n, y);
	}
	int query(int root, int l, int r, int ql, int qr, int k) {
		if (l == ql && r == qr) {
			vector <point> &s = a[root].a;
			while (s.size() >= 2 && s.back().y - s.back().x * k >= s[s.size() - 2].y - s[s.size() - 2].x * k) s.pop_back();
			return s.back().y - s.back().x * k;
		}
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr, k);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr, k);
		else return min(query(a[root].lc, l, mid, ql, mid, k), query(a[root].rc, mid + 1, r, mid + 1, qr, k));
	}
	int query(int l, int r, int k) {
		return query(root, 0, n, l, r, k);
	}
} Q;
struct SegmentTreeA {
	struct Node {
		int lc, rc;
		vector <point> a;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		vector <point> &s = a[root].a; s.clear();
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void modify(int root, int l, int r, int ql, int qr, point p) {
		if (l == ql && r == qr) {
			vector <point> &s = a[root].a;
			if (s.size() >= 1 && s.back().x == p.x && s.back().y <= p.y) return;
			while (s.size() >= 2 && (p - s.back()) * (s.back() - s[s.size() - 2]) >= 0) s.pop_back();
			s.push_back(p);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), p);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, p);
	}
	void modify(int l, int r, point p) {
		modify(root, 1, n, l, r, p);
	}
	int query(int root, int l, int r, int pos) {
		vector <point> &s = a[root].a;
		while (s.size() >= 2 && s.back().y + s.back().x * pos >= s[s.size() - 2].y + s[s.size() - 2].x * pos) s.pop_back();
		int ans = INT_MAX;
		if(s.size()) ans = s.back().y + s.back().x * pos;
		if (l == r) return ans;
		int mid = (l + r) / 2;
		if (mid >= pos) chkmin(ans, query(a[root].lc, l, mid, pos));
		else chkmin(ans, query(a[root].rc, mid + 1, r, pos));
		return ans;
	}
	int query(int pos) {
		return query(root, 1, n, pos);
	}
} A;
int n, m, a[MAXN], p[MAXN], dp[MAXN];
int fl[MAXN], fr[MAXN];
int ql[MAXN], qr[MAXN], b[MAXN];
void work(int from) {
	Q.init(n, dp);
	for (int i = n; i >= 1; i--) {
		int pos = p[i];
		b[pos] = Q.query(ql[pos] - 1, pos - 1, a[pos]);
	}
	A.init(n);
	for (int i = 1; i <= n; i++) {
		int pos = p[i];
		if (pos >= from) A.modify(pos, qr[pos], (point) {a[pos], b[pos]});
	}
	for (int i = from; i <= n; i++)
		dp[i] = A.query(i);
}
int find(int *f, int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f, f[x]);
}
void merge(int x, int y) {
	if (fl[x] == 0 || fl[y] == 0) return;
	fl[find(fl, y)] = find(fl, x);
	fr[find(fr, x)] = find(fr, y);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]), p[i] = i;
	sort(p + 1, p + n + 1, [&] (int x, int y) {
		return a[x] < a[y];
	});
	for (int i = 1; i <= n; i++) {
		int pos = p[i];
		fl[pos] = fr[pos] = pos;
		merge(pos - 1, pos);
		merge(pos, pos + 1);
		ql[pos] = find(fl, pos);
		qr[pos] = find(fr, pos);
	}
	for (int i = 1; i <= n; i++)
		dp[i] = max(dp[i - 1], a[i]);
	for (int i = 1; i <= n; i++)
		dp[i] = dp[i] * i;
	for (int i = 2; i <= m; i++)
		work(i);
	cout << dp[n] << endl;
	return 0;
}