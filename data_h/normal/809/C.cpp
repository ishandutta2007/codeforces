#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int l, r, u, d, k;

int bin(int a, int i) {
	return a & ((1 << i) - 1);
}

int sum(int k) {
	return 1LL * (1 + k) * k / 2 % MOD;
}

void add(int &a, int b) {
	if ((a += b) >= MOD) a -= MOD;
}

int dfs(int i, int a, int b, int k, int d = 0) {
	if (i < 0) return (d + 1) % MOD;
	if (a > b) swap(a, b);
	// cout << i << " " << a << " " << b << " " << k << endl;
	if (b + 1 == (1LL << (i + 1))) {
		// cout << "add " << (1LL * (a + 1) * sum(k + 1) % MOD + 1LL * (a + 1) * (k + 1) % MOD * d % MOD) % MOD << endl;
		return (1LL * (a + 1) * sum(k + 1) % MOD + 1LL * (a + 1) * (k + 1) % MOD * d % MOD) % MOD;
	} else {
		int ret = 0, mv = (1LL << i) - 1;
		int ai = (a >> i & 1), bi = (b >> i & 1), ki = (k >> i & 1);
		for (int aa = 0; aa <= ai; aa++) {
			for (int bb = 0; bb <= bi; bb++) {
				if ((aa ^ bb) > ki) continue;
				add(ret, dfs(i - 1, aa < ai ? mv : a - (ai << i),
									bb < bi ? mv : b - (bi << i),
									(aa ^ bb) < ki ? mv : k - (ki << i),
									(d + ((aa ^ bb) << i)) % MOD
							));
			}
		}
		return ret;
	}
}

int solve(int a, int b, int k) {
	if (a > b) swap(a, b);
	if (a < 0) return 0;
	return dfs(31, a, b, k);
}

int main() {
	// cout << solve(3, 2, 2) << endl;
	// return 0;
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d %d %d", &l, &d, &r, &u, &k);
		l--, d--, r--, u--, k--;
		int ans = (solve(r, u, k) - solve(l - 1, u, k) + MOD) % MOD;
		ans = (ans - solve(r, d - 1, k) + MOD) % MOD;
		ans = (ans + solve(l - 1, d - 1, k)) % MOD;
		cout << ans << endl;
	}
	return 0;
}