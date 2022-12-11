#include <bits/stdc++.h>

const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int MAXN = 110;
char buf[MAXN];
const int lamask = 0xf;
const int ramask = 0xf0;
const int lgmask = 0xf00;
const int rgmask = 0xf000;
const int lmmask = 0xf0000;
const int rmmask = 0xf00000;
std::unordered_map<int, int> M[2];
struct info {
	int la, ra, lg, rg, lm, rm;
} ;
info decode(int v) {
	info res;
	res.la = v & 0xf;
	res.ra = (v >> 4) & 0xf;
	res.lg = (v >> 8) & 0xf;
	res.rg = (v >> 12) & 0xf;
	res.lm = (v >> 16) & 0xf;
	res.rm = (v >> 20) & 0xf;
	return res;
}
int encode(info v) {
	int res = 0;
	res |= v.la;
	res |= v.ra << 4;
	res |= v.lg << 8;
	res |= v.rg << 12;
	res |= v.lm << 16;
	res |= v.rm << 20;
	return res;
}
int pat[10], qat[10];
// +, >, |
void trans(int dig, int num, int * at, int & a, int & g, int & m) {
	num += a;
	int nd = num % 10; a = num / 10;
	if (nd != dig) g = nd > dig;
	if (at[nd] != -1) m |= 1 << at[nd];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf; int n = strlen(buf);
	std::reverse(buf, buf + n);
	int Ans = 0;
	for (int i = 0; i != n; ++i) buf[i] -= '0';
	for (int i = n - 1; ~i; --i)
		Ans = ((LL) Ans * 10 + buf[i]) % mod;
	auto num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	M[0].rehash(200000);
	M[1].rehash(200000);
	for (int p : num) for (int q : num) if (gcd(p, q) == 1) {
		if (p == 1 && q == 1) continue;
		memset(pat, -1, sizeof pat);
		memset(qat, -1, sizeof qat);
		int lb = 0, rb = 0;
		for (int pw = 1; pw <= 10 && pw * p < 10 && pw * q < 10; ++pw)
			pat[p * pw] = lb++, qat[q * pw] = rb++;
		int now = 0, lst = 1;
		M[now].clear();
		M[now][encode((info) {0, 0, 0, 0, 0, 0})] = 1;
		for (int i = 0; i < n; ++i) {
			std::swap(now, lst);
			M[now].clear();
			for (auto T : M[lst]) {
				info st = decode(T.first); int v = T.second;
				for (int j = 0; j < 10; ++j) {
					info t = st;
					trans(buf[i], j * p, pat, t.la, t.lg, t.lm);
					trans(buf[i], j * q, qat, t.ra, t.rg, t.rm);
					reduce(M[now][encode(t)] += v - mod);
				}
			}
		}
		for (auto T : M[now]) {
			info t = decode(T.first);
			if (!t.la && !t.lg && !t.ra && !t.rg && (t.lm & t.rm))
				reduce(Ans += T.second - mod);
		}
	}
	std::cout << Ans << std::endl;
	return 0;
}