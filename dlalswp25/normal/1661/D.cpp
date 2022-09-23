#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
ll B[303030];
ll C[303030];
ll D[303030];
ll E[303030];

void add(int l, int r, ll x) {
	E[l] += (r - l + 1) * x;
	E[l + 1] -= (r - l + 1 + 1) * x;
	E[r + 2] += x;
}

void upd(int i) {
	D[i] = D[i - 1] + E[i];
	C[i] = C[i - 1] + D[i];
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	reverse(B + 1, B + N + 1);

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		upd(i);
		if(B[i] <= C[i]) continue;
		int k = min(K, N - i + 1);
		ll t = (B[i] - C[i] + k - 1) / k;
		if(i <= N - K + 1) add(i, i + K - 1, t);
		else add(i, N, t);
		ans += t;
		upd(i);
	}
	printf("%lld\n", ans);
	return 0;
}