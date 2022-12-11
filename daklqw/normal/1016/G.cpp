#include <bits/stdc++.h>

typedef long long LL;
typedef std::pair<LL, int> pi;
typedef std::vector<pi> V;
std::mt19937_64 rd(time(0) + (size_t) new char);
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
const LL deb = 12243;
namespace fact {
	typedef long double LD;
	LL mul(LL a, LL b, LL mod) {
		LL t = a * b - (LL) ((LD) a * b / mod + 0.5) * mod;
		return t + (t >> 63 & mod);
	}
	LL pow(LL a, LL b, LL mod, LL res = 1) {
		for (; b; b >>= 1, a = mul(a, a, mod))
			if (b & 1) res = mul(res, a, mod);
		return res;
	}
	const int pri[] = {2, 3, 5, 7, 19260817, 998244353, 1004535809};
	const int TL = 7;
	bool ispri(int x) {
		if (x < 2) return false;
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0) return false;
		return true;
	}
	bool MR(LL x) {
		if (x <= 100) return ispri(x);
		for (int i = 0; i < TL; ++i) {
			if (x == pri[i]) return true;
			LL b = pri[i] % x, t = pow(b, x - 1, x);
			if (t != 1) return false;
			LL now = x - 1;
			while (~now & 1) {
				t = pow(b, now >>= 1, x);
				if (t == x - 1) break;
				if (t != 1) return false;
			}
		}
		return true;
	}
	LL pollard(LL x) {
		LL x1 = rd() % (x - 1) + 1, x2 = x1;
		LL C = rd() % (x - 1) + 1, mx = 1;
		int stp = 0, lst = 1;
		while (true) {
			x2 = mul(x2, x2, x);
			x2 += C - x, x2 += x2 >> 63 & x;
			if (x1 == x2) return x;
			LL t = mul((x2 - x1 + x) % x, mx, x);
			if (t) mx = t;
			if ((stp & 127) == 0) {
				t = gcd(mx, x);
				if (t != x && t != 1) return t;
			}
			if (++stp == lst) x1 = x2, lst <<= 1;
		}
		return 12243; // ???
	}
	std::map<LL, int> hav;
	void _factor(LL x, int c = 1) {
		if (x == 1) return ;
		if (MR(x)) return (void) (hav[x] += c);
		LL t;
		while ((t = pollard(x)) == x) ;
		int tc = 0;
		while (x % t == 0) x /= t, ++tc;
		_factor(x, c); _factor(t, tc * c);
	}
	V factor(LL x) {
		hav.clear();
		_factor(x);
		V res;
		for (auto t : hav) res.push_back(t);
		return res;
	}
	V factorhint(LL x, V y) {
		V res;
		for (auto t : y) {
			int tc = 0;
			while (x % t.first == 0) x /= t.first, ++tc;
			res.emplace_back(t.first, tc);
		}
		res.emplace_back(deb, x > 1);
		return res;
	}
}
LL X, Y;
int n;
const int MAXN = 16;
int f[1 << MAXN], g[1 << MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> X >> Y;
	if (Y % X != 0) return std::cout << 0 << std::endl, 0;
	V _y = fact::factor(Y), y = _y;
	y.emplace_back(deb, 0);
	V x = fact::factorhint(X, _y);
	const int m = y.size();
	int mk = 0;
	for (int i = 1; i <= n; ++i) {
		LL T; std::cin >> T;
		V t = fact::factorhint(T, _y);
		int s1 = 0, s2 = 0, k = 0;
		for (int j = 0; j != m; ++j) {
			if (y[j] < t[j]) s1 = -1;
			if (x[j] > t[j]) s2 = -1;
			if (x[j] != y[j]) {
				if (y[j] > t[j]) s1 |= 1 << k;
				if (x[j] < t[j]) s2 |= 1 << k;
				++k;
			}
		}
		mk = std::max(k, mk);
		if (s1 != -1) ++f[s1];
		if (s2 != -1) ++g[s2];
	}
	const int U = 1 << mk;
	LL ans = 0;
	for (int i = 0; i != U; ++i) {
		const int I = U - i - 1;
		int t = 0;
		for (int j = I; ; j = j - 1 & I) {
			t += f[j];
			if (!j) break;
		}
		ans += (LL) g[i] * t;
	}
	std::cout << ans << std::endl;
	return 0;
}