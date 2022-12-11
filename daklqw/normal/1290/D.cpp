#include <bits/stdc++.h>

#define FL std::cout.flush()
const int MAXN = 1025;
int n, K, B;
int L[MAXN], R[MAXN];
int hav[MAXN];
int ct;
int qry(int x) {
	std::cout << "? " << x << '\n'; FL;
	static char res[100]; std::cin >> res;
	++ct;
	return *res == 'Y';
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	if (K == 1) {
		for (int D = 1; D < n; ++D) {
			for (int l = 1; l <= D && l + D <= n; ++l) {
				std::cout << "R\n"; FL;
				for (int i = l; i <= n; i += D) {
					hav[i] |= qry(i);
				}
			}
		}
	} else {
		B = n / K * 2;
		for (int i = 1; i <= B; ++i) {
			L[i] = R[i - 1] + 1;
			R[i] = L[i] + K / 2 - 1;
		}
		for (int D = 1; D < n; ++D) {
			for (int l = 1; l <= D && l + D <= B; ++l) {
				std::cout << "R\n"; FL;
				for (int i = l; i <= B; i += D) {
					for (int j = 0; j != K / 2; ++j)
						hav[L[i] + j] |= qry(L[i] + j);
				}
			}
		}
	}
	int ans = 0;
//	for (int i = 1; i <= n; ++i) std::cout << hav[i] << ' ';
//	std::cout << std::endl;
	for (int i = 1; i <= n; ++i) if (!hav[i]) ++ans;
	std::cout << "! " << ans << std::endl; FL;
	std::cerr << "FIN " << ct << ' ' << n * n * 3 / K / 2. << std::endl;
	return 0;
}