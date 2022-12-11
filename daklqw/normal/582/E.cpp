#include <bits/stdc++.h>

const int MAXN = 510;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int dp[MAXN / 3][1 << 16], idx;
char buf[MAXN];
int n, A[4];
void conv(int * tar, int * A, int * B, int typ) {
	const int lim = 1 << n;
	static int ta[1 << 16], tb[1 << 16];
	memcpy(ta, A, lim << 2); memcpy(tb, B, lim << 2);
	for (int mid = 1; mid != lim; mid <<= 1) {
		int d1 = mid, d2 = 0; if (typ == 1) std::swap(d1, d2);
		for (int k = 0; k != lim; k += mid << 1)
			for (int l = 0; l != mid; ++l) {
				reduce(ta[l + k + d1] += ta[l + k + d2] - mod);
				reduce(tb[l + k + d1] += tb[l + k + d2] - mod);
			}
	}
	for (int i = 0; i != lim; ++i) ta[i] = mul(ta[i], tb[i]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		int d1 = mid, d2 = 0; if (typ == 1) std::swap(d1, d2);
		for (int k = 0; k != lim; k += mid << 1)
			for (int l = 0; l != mid; ++l)
				reduce(ta[l + k + d1] -= ta[l + k + d2]);
	}
	for (int i = 0; i != lim; ++i) reduce(tar[i] += ta[i] - mod);
}
inline int cx(int x) { return x == '(' ? 1 : (x == ')' ? -1 : 0); }
int * solve(char * L, char * R) {
	int * f = dp[++idx];
	char * now = L + 1;
	bool be = false;
	if (*L == '(') {
		int st = 1;
		while (st) st += cx(*now++);
		if (now == R) be = true, now = L + 1;
	} else be = true, now = L;
	if (be) {
		const int U = 1 << n;
		if (*now == '?') {
			for (int i = 0; i != 4; ++i)
				++f[A[i]], ++f[A[i] ^ (U - 1)];
		} else {
			int typ = std::toupper(*now) - 'A';
			int v = A[typ]; if (*now >= 'a') v ^= U - 1;
			f[v] = 1;
		}
	} else {
		int * l = solve(L + 1, now - 1), * r = solve(now + 2, R - 1);
		if (*now == '?')
			conv(f, l, r, 0), conv(f, l, r, 1);
		else if (*now == '&') conv(f, l, r, 1);
		else conv(f, l, r, 0);
	}
	return f;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf >> n;
	int Ans = 0;
	for (int i = 0, t; i != n; ++i) {
		for (int j = 0; j != 4; ++j)
			std::cin >> t, A[j] |= t << i;
		std::cin >> t; Ans |= t << i;
	}
	std::cout << solve(buf, buf + strlen(buf))[Ans] << std::endl;
	return 0;
}