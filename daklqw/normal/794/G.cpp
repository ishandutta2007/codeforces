#include <bits/stdc++.h>

const int MAXN = 300010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
char S[MAXN], T[MAXN];
int n, A, B;
int hav[MAXN];
const int MAXS = MAXN << 1;
int fac[MAXS], inv[MAXS], pw2[MAXS];
inline int C(int x, int y) { return x < y ? 0 : (LL) fac[x] * inv[y] % mod * inv[x - y] % mod; }
int cx[3], cy[3];
int trans(int x) { return x == '?' ? 2 : x - 'A'; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = pw2[0] = 1;
	for (int i = 2; i != MAXS; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXS; ++i) inv[i] = mul(inv[i - 1], inv[i]);
	for (int i = 1; i != MAXS; ++i) reduce(pw2[i] = pw2[i - 1] * 2 - mod);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> S >> T >> n; int sm = 0;
	for (int i = n; i; --i) {
		hav[i] = (LL) (n / i) * (n / i) % mod;
		for (int j = i + i; j <= n; j += i)
			reduce(hav[i] -= hav[j]);
		reduce(sm += mul(hav[i], pw2[i]) - mod);
	}
	A = strlen(S), B = strlen(T);
	for (int i = 0; i != A; ++i) ++cx[trans(S[i])];
	for (int i = 0; i != B; ++i) ++cy[trans(T[i])];
	int Ans = 0;
	for (int dta = -cy[2]; dta <= cx[2]; ++dta) {
		int da = cx[0] - cy[0] + dta;
		int db = cx[1] - cy[1] + (cx[2] - cy[2] - dta);
		int coef = C(cx[2] + cy[2], cy[2] + dta);
		// std::cout << "DBG " << da << ' ' << db << " : " << dta << ' ' << coef << std::endl;
		if (da == 0 && db == 0) {
			int dd = 0;
			if (A == B) {
				for (int i = 0; i < A; ++i) {
					if (S[i] != '?' && T[i] != '?') {
						if (S[i] != T[i]) dd = 0xcfcfcfcf;
					} else if (S[i] == '?' && T[i] == '?') ++dd;
				}
				if (dd >= 0) {
					reduce(coef -= pw2[dd]);
					reduce(Ans += pow(pw2[n + 1] - 2 + mod, 2, pw2[dd]) - mod);
				}
			}
			// std::cout << "DD " << coef << ' ' << dd << std::endl;
			reduce(Ans += mul(coef, sm) - mod);
		} else if ((LL) da * db < 0) {
			da = std::abs(da), db = std::abs(db);
			int tn;
			reduce(tn = pw2[n / (std::max(da, db) / gcd(da, db)) + 1] - 2);
			// std::cout << "NOW " << da << ' ' << db << " : " << tn << std::endl;
			reduce(Ans += mul(tn, coef) - mod);
		}
	}
	std::cout << Ans << std::endl;
	return 0;
}