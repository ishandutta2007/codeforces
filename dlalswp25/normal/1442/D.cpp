#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
ll ans;
ll D[3030];
ll tot[3030];
vector<int> A[3030];
int sz[3030];

void dnc(int s, int e) {
	if(s == e) {
		ans = max(ans, D[K]);
		ll sum = 0;
		for(int i = 1; i <= min(sz[s], K); i++) {
			sum += A[s][i];
			ans = max(ans, D[K - i] + sum);
		}
		// printf("%d %lld\n", s, ans);
		return;
	}

	int m = s + e >> 1;
	ll tmp[3030];
	for(int i = 1; i <= K; i++) tmp[i] = D[i];

	for(int i = s; i <= m; i++) {
		for(int j = K; j >= sz[i]; j--) {
			D[j] = max(D[j], D[j - sz[i]] + tot[i]);
		}
	}
	dnc(m + 1, e);

	for(int i = 1; i <= K; i++) D[i] = tmp[i];

	for(int i = m + 1; i <= e; i++) {
		for(int j = K; j >= sz[i]; j--) {
			D[j] = max(D[j], D[j - sz[i]] + tot[i]);
		}
	}
	dnc(s, m);
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		A[i].push_back(0);
		scanf("%d", &sz[i]);
		for(int j = 1; j <= sz[i]; j++) {
			int x; scanf("%d", &x);
			A[i].push_back(x);
			tot[i] += x;
		}
	}

	dnc(1, N);
	printf("%lld\n", ans);
	return 0;
}