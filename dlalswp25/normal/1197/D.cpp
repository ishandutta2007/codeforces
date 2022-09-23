#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M, K;
ll A[303030];
ll S[303030];

priority_queue<ll> pq;

ll ans = 0;

int main() {
	scanf("%lld%lld%lld", &N, &M, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

	for(int i = 0; i < M; i++) {
		while(pq.size()) pq.pop();
		pq.push(-S[i]);

		for(int j = i + 1; j <= N; j++) {
			ans = max(ans, (j - i - 1) / M * (-K) + pq.top() + S[j] - K);
			//printf("%d %d %lld\n", i, j, ans);

			if((j - i) % M == 0) {
				pq.push((j - i) / M * K - S[j]);
			}
		}
	}
	printf("%lld\n", ans);

	return 0;
}