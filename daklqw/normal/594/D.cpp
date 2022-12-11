#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}

const int MAXS = 1e6 + 1;
int pri[MAXS], npri[MAXS], tot;
int fac[MAXS], inv[MAXS];
void sieve() {
	inv[0] = inv[1] = 1;
	fac[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		inv[i] = mul(inv[mod % i], mod - mod / i);
		if (!npri[i])
			fac[pri[++tot] = i] = i;
		for (int j = 1, t; j <= tot && (t = i * pri[j]) < MAXS; ++j) {
			npri[t] = true;
			fac[t] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int A[MAXN];
int n, m;
int pre[MAXN];
int tr[MAXN];
void add(int x, int v) {
	for (; x; x &= x - 1) tr[x] = mul(tr[x], v);
}
int lst[MAXS], ansl[MAXN];
int ls[MAXN];
std::vector<int> qs[MAXN];
int qry(int x) {
	int r = 1;
	for (; x <= n; x += x & -x) r = mul(r, tr[x]);
	return r;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	sieve();
	std::cin >> n;
	pre[0] = 1;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		pre[i] = mul(pre[i - 1], A[i]);
		tr[i] = 1;
	}
	std::cin >> m;
	for (int i = 1, r; i <= m; ++i) {
		std::cin >> ls[i] >> r;
		qs[r].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		std::set<int> hl;
		int x = A[i];
		while (x > 1) hl.insert(fac[x]), x /= fac[x];
		for (auto t : hl) {
			add(lst[t], mul(inv[t - 1], t));
			add(lst[t] = i, mul(inv[t], t - 1));
		}
		for (auto t : qs[i]) {
			ansl[t] = pow(pre[ls[t] - 1], mod - 2, pre[i]);
			ansl[t] = mul(ansl[t], qry(ls[t]));
		}
	}
	for (int i = 1; i <= m; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}