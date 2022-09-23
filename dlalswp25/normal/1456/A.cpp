#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int p, k;
ll x, y;
char A[101010];
ll D[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &p, &k);
		scanf("%s", A + 1);
		scanf("%lld%lld", &x, &y);

		for(int i = N; i >= N - k + 1; i--) {
			D[i] = (A[i] == '0') * x;
		}
		for(int i = N - k; i >= 1; i--) {
			D[i] = D[i + k] + (A[i] == '0') * x;
		}

		ll ans = 1LL << 60;
		for(int i = 0; i <= N - p; i++) {
			ans = min(ans, i * y + D[i + p]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}