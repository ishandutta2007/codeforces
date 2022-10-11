#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long mod = 1000000007;
long long N, M, A[1 << 18], B[1 << 18], C[1 << 18], rets, ans;
vector<int> X[1 << 18]; bool used[1 << 18];

void dfs(int pos) {
	if (used[pos] == true) return;
	used[pos] = true; rets++;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i]);
}

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
		if (C[i] == 0) {
			X[A[i]].push_back(B[i]);
			X[B[i]].push_back(A[i]);
		}
	}
	ans = modpow(N, M, mod);
	for (int i = 1; i <= N; i++) {
		if (used[i] == true) continue;
		rets = 0; dfs(i);
		ans -= modpow(rets, M, mod);
	}
	ans += mod * mod; ans %= mod;
	cout << ans << endl;
	return 0;
}