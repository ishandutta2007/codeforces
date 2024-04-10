#include <bits/stdc++.h>

const int MAXN = 1000010;
typedef long long LL;
typedef long double db;
typedef LL VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	VT operator ^ (vec b) const { return x * b.y - y * b.x; }
	VT operator * (vec b) const { return x * b.x + y * b.y; }
	VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	friend bool operator < (const vec & a, const vec & b) {
		return (a ^ b) > 0;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ;
typedef std::pair<vec, int> pi;
int bel[MAXN], lll[MAXN], rrr[MAXN];
int discr(std::vector<pi> v, int * tar) {
	const int L = v.size();
	std::sort(v.begin(), v.end());
	int rnk = 0;
	for (int i = 0; i != L; ++i) {
		if (i != 0 && !(v[i].first < v[i - 1].first || v[i - 1].first < v[i].first)) ;
		else ++rnk;
		bel[tar[v[i].second] = i + 1] = rnk;
		if (!lll[rnk]) lll[rnk] = i + 1;
		rrr[rnk] = i + 1;
	}
	return L;
}
vec ps[MAXN];
int opt[MAXN], xs[MAXN], ys[MAXN]; 
const int NINF = 0xcfcfcfcf;
int tree[MAXN << 2];
void add(int u, int l, int r, int tar, int v) {
	if (l == r) return (void) (tree[u] = v);
	int mid = l + r >> 1;
	if (tar <= mid) add(u << 1, l, mid, tar, v);
	else add(u << 1 | 1, mid + 1, r, tar, v);
	tree[u] = std::max(tree[u << 1], tree[u << 1 | 1]);
}
int qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1, res = NINF;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = std::max(res, qry(u << 1 | 1, mid + 1, r, L, R));
	return res;
}
int n;
inline int tr(int x, int y) { return x == 1 ? y : NINF; }
int nl;
void add(int i, int v) {
	add(1, 1, nl, ys[i], tr(v, xs[i]));
}
LL R;
bool incir(vec x, vec y) {
	return (x * y) < 0 || (x ^ y) <= 0;
}
int trans[MAXN];
int main() {
	memset(tree, 0xcf, sizeof tree);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> R >> n;
	vec pol(-R, 0), por(R, 0);
	std::vector<pi> ll;
	for (int i = 1, bak = 0; i <= n; ++i) {
		std::cin >> opt[i] >> xs[i];
		if (opt[i] != 2) std::cin >> ys[i];
		if (opt[i] == 1) {
			ps[i] = vec(xs[i], ys[i]);
			ll.emplace_back(ps[i] - pol , i);
			ll.emplace_back(ps[i] - por, i + n);
			trans[++bak] = i;
		} else xs[i] = trans[xs[i]], ys[i] = trans[ys[i]];
	}
	static int ls[MAXN << 1], app[MAXN];
	nl = discr(ll, ls);
	for (int i = 1; i <= n; ++i) if (opt[i] == 1)
		xs[i] = ls[i], ys[i] = ls[i + n];
//	for (int i = 1; i <= n; ++i)
//		std::cout << xs[i] << ' ' << ys[i] << std::endl;
	for (int T = 1; T <= n; ++T) {
		if (opt[T] == 1) add(T, 1), app[T] = true;
		else if (opt[T] == 2) add(xs[T], -1), app[xs[T]] = false;
		else {
			bool can = true;
			int A = xs[T], B = ys[T];
			if (!incir( std::min(ps[A] - pol, ps[B] - pol),
						std::max(ps[A] - por, ps[B] - por) )) {
				int l = lll[bel[std::min(xs[A], xs[B])]];
				int r = rrr[bel[std::max(ys[A], ys[B])]];
				if (app[A]) add(A, -1);
				if (app[B]) add(B, -1);
				can = qry(1, 1, nl, 1, r) >= l;
				if (app[A]) add(A, 1);
				if (app[B]) add(B, 1);
			}
			std::cout << (can ? "NO" : "YES") << '\n';
		}
	}

	return 0;
}