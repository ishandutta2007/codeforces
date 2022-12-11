#include <bits/stdc++.h>

const int MAXN = 50010;
typedef long long LL;
int mod;

struct mat {
	int a00, a01, a10, a11;
	friend mat operator * (mat a, mat b) {
		return (mat) {
			(int) (((LL) a.a00 * b.a00 + (LL) a.a01 * b.a10) % mod),
			(int) (((LL) a.a00 * b.a01 + (LL) a.a01 * b.a11) % mod),
			(int) (((LL) a.a10 * b.a00 + (LL) a.a11 * b.a10) % mod),
			(int) (((LL) a.a10 * b.a01 + (LL) a.a11 * b.a11) % mod)
		};
	}
} tree[MAXN << 2];
std::ostream & operator << (std::ostream & out, mat x) {
	out << '[' << x.a00 << ',' << x.a01 << ',' << x.a10 << ',' << x.a11 << ']';
	return out;
}
const mat I = (mat) {1, 0, 0, 1};
inline mat get(int l, int r) {
	return (mat) {r, l, 1, 0};
}
int S[MAXN];
int n, m; LL K;
void build(int u = 1, int l = 0, int r = n - 1) {
	if (l == r)
		return (void) (tree[u] = get(S[(l - 1 + n) % n], S[l]));
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	tree[u] = tree[u << 1 | 1] * tree[u << 1];
}
mat query(int L, int R, int u = 1, int l = 0, int r = n - 1) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1; mat res = I;
	if (L <= mid) res = query(L, R, u << 1, l, mid);
	if (mid < R) res = query(L, R, u << 1 | 1, mid + 1, r) * res;
	return res;
}
std::map<LL, int> li;
mat pow(mat a, LL b, mat res = I) {
	for (; b; b >>= 1, a = a * a) if (b & 1) res = res * a;
	return res;
}
mat getmat(LL l, LL r) {
	if (l > r) return I;
	if (l / n == r / n) return query(l % n, r % n);
	mat res = query(l % n, n - 1);
	res = pow(tree[1], r / n - l / n - 1) * res;
	res = query(0, r % n) * res;
	return res;
}
int main() {
	std::cin >> K >> mod >> n;
	if (K == 0) return std::cout << 0 << std::endl, 0;
	if (K == 1) return std::cout << 1 % mod << std::endl, 0;
	K -= 1;
	for (int i = 0; i != n; ++i) std::cin >> S[i], S[i] %= mod;
	build();
	std::cin >> m;
	for (int i = 0; i != m; ++i) {
		LL lhs; int rhs;
		std::cin >> lhs >> rhs; rhs %= mod;
		if (lhs <= K) li[lhs] = rhs;
	}
	mat now = (mat) {1, 0, 0, 0};
	if (!li.count(K)) li[K] = S[K % n];
	std::vector<std::pair<LL, int> > tp;
	auto vat = [] (LL t) { return li.count(t) ? li[t] : S[t % n]; };
	for (auto t : li) {
		LL p = t.first;
		if (p < K) tp.emplace_back(p + 1, vat(p + 1));
	}
	for (auto t : tp) li[t.first] = t.second;
	LL lst = 0;
	for (auto t : li) if (t.first) {
		now = getmat(lst + 1, t.first - 1) * now;
		now = get(vat(t.first - 1), vat(t.first)) * now;
		lst = t.first;
	}
	std::cout << now.a00 % mod << std::endl;
	return 0;
}