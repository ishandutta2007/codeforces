#include <bits/stdc++.h>

const int MAXN = 1000010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
LL A[MAXN]; int fa[MAXN], n;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
std::map<LL, int> hav;
std::vector<LL> can;
void solve(LL x) {
	LL y = A[1] / x;
	if (y > n) return ;
	int c = 0;
	for (auto t : hav) if (t.first % x == 0) c += t.second;
	if (c == y - 1) can.push_back(x);
	assert(c <= y - 1);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 2; i <= n; ++i) std::cin >> fa[i];
	for (int i = n; i > 1; --i) A[fa[i]] += A[i];
	for (int i = 2; i <= n; ++i) ++hav[gcd(A[i], A[1])];
	for (int i = 1; (LL) i * i <= A[1]; ++i) if (A[1] % i == 0) {
		solve(i); if ((LL) i * i != A[1]) solve(A[1] / i);
	}
	hav.clear();
	std::sort(can.rbegin(), can.rend());
	int ans = 0;
	hav[A[1]] = 1;
	for (auto t : can) {
		for (auto p : can) if (p > t && p % t == 0)
			reduce(hav[t] += hav[p] - mod);
		reduce(ans += hav[t] - mod);
	}
	std::cout << ans << std::endl;
	return 0;
}