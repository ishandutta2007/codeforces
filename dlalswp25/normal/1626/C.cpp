#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int K[105];
int H[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &K[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &H[i]);
		for(int i = N - 1; i >= 1; i--) {
			H[i] = max(H[i], H[i + 1] - (K[i + 1] - K[i]));
		}
		ll ans = (ll)H[1] * (H[1] + 1) / 2;
		for(int i = 2; i <= N; i++) {
			if(K[i] - K[i - 1] >= H[i]) {
				ans += (ll)H[i] * (H[i] + 1) / 2;
				continue;
			}
			if(H[i] - H[i - 1] < K[i] - K[i - 1]) {
				H[i] = H[i - 1] + K[i] - K[i - 1];
			}
			ans += (ll)H[i] * (H[i] + 1) / 2;
			ans -= (ll)H[i - 1] * (H[i - 1] + 1) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}