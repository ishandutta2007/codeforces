#include <bits/stdc++.h>

const int MAXN = 5010;
typedef long long LL;
int n, m;
std::map<int, int> hav;
int A[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m; int tm = m;
//	int can = 0;
//	for (int i = 1; i <= n; ++i)
//		for (int j = i + 1; j <= n; ++j)
//			can += i + j <= n;
//	std::cerr << can << std::endl;
	int i;
	for (i = 1; i <= n && m; ++i) {
		if (hav[i] > m) {
			int t = i;
			while (hav[t] > m) ++t;
			A[i] = t; ++i;
			assert(hav[t] == m);
			m -= hav[t];
			break;
		} else {
			m -= hav[i];
			A[i] = i;
			for (int j = 1; j < i; ++j) ++hav[j + i];
		}
	}
//	std::cerr << "REST " << m << std::endl;
	if (m) return std::cout << -1 << std::endl, 0;
	for (int j = n, now = 1e9; j >= i; --j) {
		A[j] = now, now -= n + i + 1;
	}
	for (i = 1; i <= n; ++i) std::cout << A[i] << ' ';
	std::cout << std::endl;
//	hav.clear();
//	for (i = 1; i <= n; ++i)
//		for (int j = i + 1; j <= n; ++j)
//			++hav[A[i] + A[j]];
//	long long ta = 0;
//	for (int i = 1; i <= n; ++i) ta += hav[A[i]];
//	std::cout << "QRY " << tm << " GET " << ta << std::endl;
//	assert(ta == tm);
	return 0;
}