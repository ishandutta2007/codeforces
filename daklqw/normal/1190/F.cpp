#include <bits/stdc++.h>

typedef long long LL;
typedef long double LD;
void bye() { std::cout << -1 << std::endl; exit(0); }

namespace NumberTheory {
	std::mt19937_64 rd(time(0) + (unsigned long) new char);
	typedef std::pair<LL, int> fac;
	typedef std::pair<LL, LL> dbp;
	void reduce(LL & x, const LL P) { x += x >> 63 & P; }
	inline LL mul(LL x, LL y, LL P) {
		LL t = x * y - (LL) ((LD) x * y / P + 0.5) * P;
		return t + (t >> 63 & P);
	}
	inline LL fastpow(LL a, LL b, LL P, LL res = 1) {
		for (; b; b >>= 1, a = mul(a, a, P)) if (b & 1)
			res = mul(res, a, P);
		return res;
	}
	inline LL fastpow(LL a, LL b) {
		LL res = 1;
		for (; b; b >>= 1, a *= a) if (b & 1) res *= a;
		return res;
	}
	LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
	namespace Prime {
		const int PL = 8;
		const LL li[PL] = {2, 3, 5, 7, 11, 13, 82, 373};
		const int MAXS = 1000;
		int pri[MAXS], ptot; bool npri[MAXS + 1];
		void sieve() {
			*npri = npri[1] = true;
			for (int i = 2; i <= MAXS; ++i) {
				if (!npri[i]) pri[++ptot] = i;
				for (int j = 1; j <= ptot; ++j) {
					int t = i * pri[j];
					if (t > MAXS) break;
					npri[t] = true;
					if (i % pri[j] == 0) break; }
			}
		}
		bool MillerRabin(LL x) {
			if (x <= MAXS) return !npri[x];
			for (int i = 0; i != PL; ++i) {
				if (x == li[i]) return true;
				if (fastpow(li[i], x - 1, x) != 1) return false;
				LL now = x - 1;
				while (~now & 1) {
					now >>= 1;
					LL t = fastpow(li[i], now, x);
					if (t != 1 && t != x - 1) return false;
					if (t == x - 1) break;
				}
			}
			return true;
		}
	}
	namespace Factor {
		LL Pollard(LL x) {
			LL x1 = rd() % (x - 1) + 1, x2 = x1;
			LL C = rd() % (x - 1) + 1, mx = 1;
			int lst = 1, stp = 0;
			while (true) {
				x2 = mul(x2, x2, x);
				reduce(x2 += C - x, x);
				if (x1 == x2) return x;
				LL t = mul(x2 - x1 + x, mx, x);
				if (t) mx = t;
				if ((stp & 127) == 0) {
					t = gcd(mx, x); mx = 1;
					if (t != 1) return t;
				}
				if (++stp == lst) lst <<= 1, x1 = x2;
			}
		}
		std::map<LL, int> li;
		void _factor(LL x, int v = 1) {
			if (x == 1) return ;
			if (Prime::MillerRabin(x)) { li[x] += v; return ; }
			LL t;
			do t = Pollard(x); while (t >= x);
			int lv = 0;
			while (x % t == 0) lv += v, x /= t;
			_factor(t, lv); _factor(x, v);
		}
		std::vector<fac> factor(LL x) {
			_factor(x);
			std::vector<fac> res;
			for (auto t : li)
				res.emplace_back(t.first, t.second);
			li.clear();
			return res;
		}
	}
	void init() {
		Prime::sieve();
	}
}
using NumberTheory::Factor::factor;
using NumberTheory::fac;
using NumberTheory::fastpow;
LL order(LL a, LL m, LL in, std::vector<fac> pri) {
	LL res = in;
	// std::cout << "ORD " << a << ' ' << m << ' ';
	// std::cout.flush();
	for (auto t : pri) {
		LL v = t.first;
		while (res % v == 0) {
			LL nt = fastpow(a, res / v, m);
			if (nt != 1) break;
			res /= v;
		}
	}
	// std::cout << res << std::endl;
	return res;
}
LL getroot(LL m, LL phi, std::vector<fac> li) {
	for (LL i = 2; ; ++i)
		if (order(i, m, phi, li) == phi)
			return i;
}
int main() {
	NumberTheory::init();
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; LL m, P;
	std::cin >> n >> m >> P;
	LL pri = factor(m)[0].first;
	LL phi = m / pri * (pri - 1);
	auto li = factor(phi);
	std::vector<LL> ansl;
	if (P % pri == 0 || m <= 10000000) {
		static std::bitset<10000010> B;
		int now = 1;
		if (P % pri != 0)
			do B[now] = true, now = now * P % m;
			while (now > 1);
		for (int i = 2; i < m && n; ++i)
			if (i % pri != 0 && !B[i])
				ansl.push_back(i), --n;
		if (n) bye();
	} else {
		LL ord = order(P, m, phi, li);
		if (phi - ord < n) bye();
		if (pri == 2 && P % 4 == 1) {
			for (int i = 0; n; ++i)
				ansl.push_back(i * 4 + 3), --n;
		} else {
			LL rt, pw;
			if (pri == 2) {
				ord /= 2;
				rt = 5;
				LL ot = order(5, m, phi, li);
				pw = ot / ord;
			} else {
				rt = getroot(m, phi, li);
				pw = phi / ord;
			}
			for (int i = 1; n; ++i) if (i % pw != 0)
				ansl.push_back(fastpow(rt, i, m)), --n;
		}
	}
	for (auto t : ansl) std::cout << t << ' ';
	std::cout << '\n';
	return 0;
}