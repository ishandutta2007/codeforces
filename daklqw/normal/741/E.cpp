#include <bits/stdc++.h>

const int MAXN = 200010;

typedef long long LL;
std::mt19937 rd(time(0) + (size_t) (new char));
bool ispri(int x) { for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false; return true; } int fnd() { int t = rd() % 1000 + 1000000000; while (!ispri(t)) ++t; return t; }
const int mod1 = fnd();
const int bse1 = rd() % 1000 + 1000;
int pw1[MAXN];
struct hasher {
	int ha1[MAXN];
	int getha(int l, int r) {
		int h1 = ha1[r] - (LL) ha1[l - 1] * pw1[r - l + 1] % mod1;
		return h1 + (h1 >> 31 & mod1);
	}
	inline int getha(int r) { return ha1[r]; }
	void init(char * buf, int n) {
		for (int i = 1; i <= n; ++i)
			ha1[i] = ((LL) ha1[i - 1] * bse1 + buf[i]) % mod1;
	}
} hs, ht;
char S[MAXN], T[MAXN];
int n, m, Q, ps[MAXN], rk[MAXN];
int getha(int x, int y) {
	if (y <= x) return hs.getha(y);
	else if (y <= x + m)
		return ((LL) hs.getha(x) * pw1[y - x] + ht.getha(y - x)) % mod1;
	else
		return ((LL) hs.getha(x) * pw1[y - x] + (LL) ht.getha(m) * pw1[y - m - x] + hs.getha(x + 1, y - m)) % mod1;
}
char charat(int x, int y) {
	if (y <= x) return S[y];
	else if (y <= x + m) return T[y - x];
	else return S[y - m];
}
int ST[18][MAXN];
void build(int n) {
	for (int i = 1; i != 18; ++i)
		for (int j = 0; j + (1 << i) - 1 <= n; ++j)
			ST[i][j] = std::min(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
}
int qry(int l, int r) {
	int L = std::__lg(r - l + 1);
	return std::min(ST[L][l], ST[L][r - (1 << L) + 1]);
}
int xs[MAXN], ys[MAXN], ls[MAXN], rs[MAXN], ansl[MAXN];
const int B = 100;
std::vector<int> hav[B + 10];
int main() {
	*pw1 = 1;
	for (int i = 1; i != MAXN; ++i)
		pw1[i] = (LL) pw1[i - 1] * bse1 % mod1;
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> S + 1 >> T + 1 >> Q;
	// for (int i = 1; i <= 100000; ++i) S[i] = T[i] = 'a';
	hs.init(S, n = strlen(S + 1));
	ht.init(T, m = strlen(T + 1));
	for (int i = 0; i <= n; ++i) ps[i] = i;
	auto cmp = [] (int a, int b) {
		int l = 1, r = n + m, at = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (getha(a, mid) == getha(b, mid)) at = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (at == n + m) return a < b;
		return charat(a, at + 1) < charat(b, at + 1);
	};
	std::sort(ps, ps + 1 + n, cmp);
	std::cerr << "FIN " << clock() / (double) CLOCKS_PER_SEC << std::endl;
	for (int i = 0; i <= n; ++i) ST[0][ps[i]] = rk[ps[i]] = i;
	build(n);
	ps[n + 1] = -1;
	for (int i = 1, k; i <= Q; ++i) {
		std::cin >> ls[i] >> rs[i] >> k >> xs[i] >> ys[i];
		if (k < B) hav[k].push_back(i), ansl[i] = n + 1;
		else {
			const int R = rs[i] / k + 1;
			int ans = n + 1;
			for (int j = ls[i] / k; j <= R; ++j) {
				int l = xs[i] + j * k, r = ys[i] + j * k;
				l = std::max(l, ls[i]), r = std::min(r, rs[i]);
				if (l <= r) ans = std::min(ans, qry(l, r));
			}
			ansl[i] = ans;
		}
	}
	for (int i = 1; i < B; ++i) if (hav[i].size()) {
		for (int j = 0; j < i; ++j) {
			int lim = 0;
			for (int k = j; k <= n; k += i, ++lim)
				ST[0][lim] = rk[k];
			build(lim - 1);
			for (auto t : hav[i]) if (xs[t] <= j && j <= ys[t]) {
				if (rs[t] < j) continue;
				int l = std::max(ls[t] - j, 0);
				int r = std::max(rs[t] - j, 0);
				l = l / i + (l % i != 0);
				r = r / i;
				if (l <= r) ansl[t] = std::min(ansl[t], qry(l, r));
			}
		}
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ps[ansl[i]] << ' ';
	return 0;
}