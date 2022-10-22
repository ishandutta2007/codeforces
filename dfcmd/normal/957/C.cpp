#include <bits/stdc++.h>

const int N = 100005;
const long double eps = 1e-12;

int n, U;
int a[N];
int h, t, Q[N];

long double calc(int i, long double x) {
	return a[i + 1] - x * a[i];
}

bool check(long double x) {
	h = 1, t = 0;
	for (int i = 2; i <= n; ++i) {
		while (h <= t && a[i] - a[Q[h]] > U) {
			++h;
		}
		if (h <= t && calc(Q[h], x) < (1 - x) * a[i] + eps) {
			return true;
		}
		while (h <= t && calc(Q[t], x) > calc(i - 1, x)) {
			--t;
		}
		Q[++t] = i - 1;
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	std::cin >> n >> U;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	
	long double l = 0, r = 1, ans = -1;
	for (int i = 1; i <= 100; ++i) {
		double mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
			ans = mid;
		} else {
			r = mid;
		}
	}
	if (ans < 0) {
		std::cout << -1 << "\n";
	} else {
		std::cout << ans << "\n";
	}
}