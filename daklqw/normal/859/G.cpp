#include <bits/stdc++.h>

int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
bool isprime(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}
int n;
const int MAXN = 100010;
char buf[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf; mod = n + 1;
	for (int i = 0; i <= 5; mod += n) if (isprime(mod)) {
		++i; int t = mod - 1, r, can = false;
		static int li[100]; int bak = 0;
		for (int j = 2; j * j <= t; ++j)
			if (t % j == 0) {
				li[++bak] = j;
				while (t % j == 0) t /= j;
			}
		if (t > 1) li[++bak] = t;
		for (r = 2; !can; ++r) {
			for (int j = can = 1; j <= bak && can; ++j)
				can &= pow(r, (mod - 1) / li[j]) != 1;
		}
		r = pow(r - 1, (mod - 1) / n);
		int sm = 0;
		for (int i = 0, t = 1; i < n; ++i, t = mul(t, r))
			reduce(sm += mul(t, buf[i] & 15) - mod);
		if (sm) return std::cout << "NO" << std::endl, false;
	}
	std::cout << "YES" << std::endl;
	return 0;
}