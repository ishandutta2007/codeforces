#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
int hav[MAXN], cnt, n, A[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], ++hav[A[i]];
	for (int i = 1; i <= n; ++i) cnt += hav[i] & 1;
	if (cnt > 1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	cnt = 0;
	int eq = 0;
	while (eq + 1 <= n - eq && A[eq + 1] == A[n - eq]) ++eq;
	LL ans = (LL) (eq + 1) * (eq + 1);
	if (eq * 2 >= n) {
		std::cout << n * (n + 1ll) / 2 << std::endl;
		return 0;
	}
	memset(hav, 0, n + 1 << 2);
	int L = eq + 1, R = n - eq;
	for (int i = L; i <= R; ++i) ++hav[A[i]];
	while (true) {
		if (L > R) {
			if (A[L] != A[R]) break;
		} else {
			hav[A[L]] -= 2 - (L == R);
			if (hav[A[L]] < 0) break;
		}
		ans += eq + 1;
		++L, --R;
	}
	memset(hav, 0, n + 1 << 2);
	L = eq + 1, R = n - eq;
	for (int i = L; i <= R; ++i) ++hav[A[i]];
	while (true) {
		if (L > R) {
			if (A[L] != A[R]) break;
		} else {
			hav[A[R]] -= 2 - (L == R);
			if (hav[A[R]] < 0) break;
		}
		ans += eq + 1;
		++L, --R;
	}
	std::cout << ans << std::endl;
	return 0;
}