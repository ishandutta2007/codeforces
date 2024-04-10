#include <bits/stdc++.h>
using namespace std;

namespace Factor {
	const int MAXN = 2000005;
	const int CERTAINTY = 8;
	const int RUNS = 20;

	int maxn, prn;
	int p[MAXN], prm[MAXN];

	vector<long long> d;

	long long fac[110];
	long long q[110], e[110];
	long long a[1000000];
	int cnt;

	using PLI = pair<long long, int>;

	inline long long mul(long long a, long long b, long long p) {
		if (p <= INT_MAX) return a * b % p;
		if (p <= 1LL<<40) return (((a * (b>>20) % p) << 20) + (a * (b & ((1<<20) - 1)))) % p;
		return (a * b - (long long)((long double)a / p * b + 1e-8) * p + p) % p;
	}
	void prime_sieve() {
		prn = 0;
		for (int i = 1; i <= maxn; i++) p[i] = i;
		for (int i = 2; i <= maxn; i++) {
			if (p[i] == i) prm[prn++] = i;
			for (int j = 0, x; j < prn && (x = i * prm[j]) <= maxn && prm[j] <= p[i]; j++) p[x] = prm[j];
		}
	}
	void init(int mxn) {
		maxn = mxn;
		prime_sieve();
	}
	long long modexponent(long long a, long long n, long long p) {
		long long ret = 1;
		for (a = (a % p + p) % p; n; n >>= 1, a = mul(a, a, p)) if (n & 1) ret = mul(ret, a, p);
		return ret;
	}
	bool witness(long long a, long long n) {
		long long u = n-1, x, y;
		int t = __builtin_ctzll(u);
		u >>= t;
		for (x = modexponent(a, u, n); t--; x = y) {
			y = mul(x, x, n);
			if (y == 1 && x != 1 && x != n-1) return 1;
		}
		return x != 1;
	}
	bool miller(long long n) {
		if (n < 2) return 0;
		if (n == 2) return 1;
		if (n <= maxn) return p[n] == n;
		if (~n & 1) return 0;
		for (int j = 0; j < CERTAINTY; j++) if (witness(rand() % (n-1) + 1, n)) return 0;
		return 1;
	}
	long long gcd(long long a, long long b) {
		long long ret = 1;
		while (a) {
			if ((~a & 1) && (~b & 1)) a >>= 1, b >>= 1, ret <<= 1;
			else if (~a & 1) a >>= __builtin_ctzll(a);
			else if (~b & 1) b >>= __builtin_ctzll(b);
			else {
				if (a < b) a ^= b ^= a ^= b;
				a -= b;
			}
		}
		return ret * b;
	}
	long long rho(long long n) {
		if (n <= 100) {
			for (int m = 2; m * m <= n; m++) if (n % m == 0) return m;
		}
		while (1) {
			int runs = RUNS;

			long long x = rand() % n, y, T = 1, *ly = a, *lx = ly;
			long long c = rand() % 10 + 3;

			x = mul(x, x, n) + c; *(ly++) = x; lx++;
			y = mul(x, x, n) + c; *(ly++) = y;

			while (x != y) {
				long long t = x - y; if (t < 0) t += n;
				long long z = mul(T, t, n);
				if (!z) return gcd(T, n);
				runs--;
				if (!runs) {
					runs = RUNS;
					z = gcd(z, n);
					if (z != 1) return z;
				}
				T = z;
				y = *(ly++) = mul(y, y, n) + c;
				y = *(ly++) = mul(y, y, n) + c;
				x = *(lx++);
			}
		}
	}
	void factorize(long long n) {
		for (int i = 0; i < cnt; i++) if (n % fac[i] == 0) n /= fac[i], fac[cnt++] = fac[i];
		if (n <= maxn) {
			for (; n > 1; n /= p[n]) fac[cnt++] = p[n];
			return;
		}
		if (n == 1) return;
		if (miller(n)) fac[cnt++] = n;
		else {
			long long x = rho(n);
			factorize(x), factorize(n / x);
		}
	}
	void norm() {
		sort(fac, fac + cnt);
		int _cnt = cnt; cnt = 0;
		for (int i = 0; i < _cnt; i++) {
			if (i == 0 || fac[i] != fac[i-1]) q[cnt] = fac[i], e[cnt++] = 1;
			else e[cnt-1]++;
		}
	}
	void dfs(long long x, int ptr) {
		if (ptr == cnt) d.push_back(x);
		else {
			dfs(x, ptr + 1);
			for (int i = 0; i < e[ptr]; i++) dfs(x *= q[ptr], ptr + 1);
		}
	}
	vector<long long> divisor(long long n) {
		cnt = 0; factorize(n); norm();
		d.clear();
		dfs(1, 0);
		return d;
	}
	vector<pair<long long, int> > factor(long long n) {
		cnt = 0; factorize(n); norm();
		vector<pair<long long, int> > ret;
		for (int i = 0; i < cnt; i++) ret.push_back(make_pair(q[i], e[i]));
		return ret;
	}
	bool is_primitive(long long g, long long p) {
		assert(miller(p));
		vector<PLI> D = factor(p - 1);
		for (int i = 0; i < D.size(); i++) if (modexponent(g, (p - 1) / D[i].first, p) == 1) return 0;
		return 1;
	}
	int get_primitive(long long p) {
		assert(miller(p));
		vector<PLI> D = factor(p - 1);
		for (int g = 1; ; g++) {
			int flg = 1;
			for (int i = 0; flg && i < D.size(); i++) flg &= (modexponent(g, (p - 1) / D[i].first, p) != 1);
			if (flg) return g;
		}
	}
};

const int N = 110000;

int cnt[110000];

const long long inf = 1.1e10;

long long exponent(long long a, int n) {
	long long ret = 1;
	for (; n; n >>= 1) {
		if (n & 1) {
			if (ret == inf || a == inf) return inf;
			if (a > inf / ret) return inf;
			ret = ret * a;
			if (ret >= inf) return inf;
		}
		if (a >= 1e6) a = inf;
		else a = a * a;
		if (a >= inf) a = inf;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Factor::init(2000000);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	long long ans = 0;
	for (long long i = 1, cur; (cur = exponent(i, k)) < inf; i++) {
		auto it = Factor::divisor(cur);
		for (long long u : it) {
			long long v = cur / u;
			if (u < v) continue;
			if (v >= N || u >= N) continue;
			if (u == v) {
				ans += cnt[u] * 1LL * (cnt[u] - 1) / 2;
			} else {
				ans += cnt[u] * 1LL * cnt[v];
			}
		}
	}
	cout << ans << "\n"; 
	return 0;
}