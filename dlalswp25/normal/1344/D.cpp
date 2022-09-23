#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll K;
ll A[101010];
ll tot;
ll B[101010];

ll f(int i, ll x) {
	return -3 * x * x + 3 * x + A[i] - 1;
}

void solve(ll M) {
	tot = 0;

	for(int i = 1; i <= N; i++) {
		int l = 1, r = A[i];
		while(l <= r) {
			int m = l + r >> 1;
			if(f(i, m) < M) r = m - 1;
			else l = m + 1;
		}
		//r
		B[i] = r;
		tot += r;
	}
}

int main() {
	scanf("%d%lld", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	ll L = -3e18, R = 1e9;
	while(L <= R) {
		ll M = L + R >> 1;

		solve(M);
		if(tot < K) R = M - 1;
		else L = M + 1;
	}
	solve(R);

	for(int i = 1; i <= N; i++) {
		while(tot > K && f(i, B[i]) == R) {
			B[i]--; tot--;
		}
	}

	for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");
	return 0;
}