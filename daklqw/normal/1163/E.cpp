#include <bits/stdc++.h>

const int MAXN = 200010;
int n, A[MAXN];
struct lb {
	int a[25], o[25], cnt;
	void ins(int x) {
		int _x = x;
		for (int i = 24; ~i; --i) if (x >> i & 1) {
			if (a[i]) x ^= a[i];
			else { a[i] = x, o[i] = _x, ++cnt; break; }
		}
	}
} b;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 24; ~i; --i) {
		memset(&b, 0, sizeof b);
		for (int j = 1; j <= n; ++j) if (A[j] < (1 << i)) b.ins(A[j]);
		if (b.cnt == i) {
			std::cout << i << std::endl;
			for (int j = 0; j < (1 << i); ++j) {
				int now = j ^ (j >> 1), v = 0;
				for (int k = 0; k != i; ++k)
					if (now >> k & 1) v ^= b.o[k];
				std::cout << v << ' ';
			}
			return 0;
		}
	}
	return 0;
}