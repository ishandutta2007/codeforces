//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 110000;

int prm[MAXN], prn;
int sum[MAXN][4], p[MAXN];

unsigned calc(int n, int k) {
	if (k == 0) return n;
	if (k == 1) {
		if (n & 1) return (n + 1) / 2 * n;
		return n / 2 * (n + 1);
	}
	if (k == 2) {
		if (n % 6 == 0) return n / 6 * (n + 1) * (2 * n + 1);
		if (n % 6 == 1) return n * ((n + 1) / 2) * ((2 * n + 1) / 3);
		if (n % 6 == 2) return n / 2 * ((n + 1) / 3) * (2 * n + 1);
		if (n % 6 == 3) return n / 3 * ((n + 1) / 2) * (2 * n + 1);
		if (n % 6 == 4) return n / 2 * ((2 * n + 1) / 3) * (n + 1);
		if (n % 6 == 5) return n * ((n + 1) / 6) * (2 * n + 1);
	}
	if (k == 3) {
		return calc(n, 1) * calc(n, 1);
	}
}

void sieve(int n) {
	p[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (1LL * i * i <= n && !p[i]) {
			p[i] = i;
			prm[prn++] = i;
		}
		for (int j = 0, k; j < prn && (k = prm[j]*i) <= n; j++) {
			if (k < MAXN) p[k] = prm[j];
			if (1LL * k * k > n) {
				for (int cur = 1, r = 0; r < 4; r++) {
					sum[n / k][r] -= cur;
					cur *= k;
				}
			}
			if (i % prm[j] == 0) break;
		}
	}
	int k = sqrt(n);
	for (int i = 1; i * i <= n; i++) {
		int L = max(k + 1, n / (i + 1) + 1);
		int R = n / i;
		if (L <= R) {
			for (int r = 0; r < 4; r++) sum[i][r] += calc(R, r) - calc(L - 1, r);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, A, B, C, D; cin >> n >> A >> B >> C >> D;
	sieve(n);
	int ans = 0;
	for (int i = 2; i * i <= n; i++) {
		if (p[i] == i) {
			int q = i;
			int m = n;
			int ret = A * i * i * i + B * i * i + C * i + D;
			while (m) {
				m /= q;
				ans += ret * m;
			}
		}
	}
	for (int i = 1; i * i <= n; i++) {
		ans += i * (sum[i][0] * D + sum[i][1] * C + sum[i][2] * B + sum[i][3] * A);
	}
	printf("%u\n", ans);
	return 0;
}