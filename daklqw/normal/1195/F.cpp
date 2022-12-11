#include <bits/stdc++.h>

const int MAXN = 300010;

typedef long long LL;
typedef long double db;
typedef int VT;
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
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN];
std::map<vec, int> lst;
typedef std::vector<vec> VP;
inline LL cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
int n;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int sgn(int x) { return x < 0 ? -1 : 1; }
vec red(vec x) {
	if (x.x == 0 || x.y == 0) {
		if (x.x != 0) x.x = sgn(x.x);
		if (x.y != 0) x.y = sgn(x.y);
	} else {
		int g = std::abs(gcd(x.x, x.y));
		x.x /= g, x.y /= g;
	}
	return x;
}
int A[MAXN], L[MAXN], R[MAXN];
int ls[MAXN], RAN;
std::vector<int> qs[MAXN];
int tree[MAXN], ansl[MAXN];
void mdf(int x, int v) {
	for (; x; x &= x - 1) tree[x] += v;
}
int qry(int x) {
	int res = 0;
	for (; x <= RAN; x += x & -x) res += tree[x];
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int m; std::cin >> m;
		R[i] = (L[i] = R[i - 1] + 1) - 1;
		for (int j = 1; j <= m; ++j) std::cin >> ps[j];
		for (int j = 1; j <= m; ++j) {
			vec t = red(ps[j == m ? 1 : j + 1] - ps[j]);
			A[++R[i]] = lst[t];
			lst[t] = R[i];
		}
	}
	RAN = R[n];
	int Q; std::cin >> Q;
	for (int i = 1, r; i <= Q; ++i)
		std::cin >> ls[i] >> r, qs[R[r]].push_back(i), ls[i] = L[ls[i]];
	for (int i = 1; i <= RAN; ++i) {
		if (A[i]) mdf(A[i], -1); mdf(i, 1);
		for (auto t : qs[i]) ansl[t] = qry(ls[t]);
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}