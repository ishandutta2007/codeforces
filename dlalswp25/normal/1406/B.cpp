#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[101010];
ll mn[6][101010];
ll mx[6][101010];

int main() {
	int tc; scanf("%d", &tc);
	for(int i = 0; i <= 100000; i++) mn[0][i] = mx[0][i] = 1;
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

		for(int i = 1; i <= 5; i++) {
			mn[i][i - 1] = 1LL << 60;
			mx[i][i - 1] = -(1LL << 60);
			for(int j = i; j <= N; j++) {
				mn[i][j] = min(min(mn[i][j - 1], mn[i - 1][j - 1] * A[j]), mx[i - 1][j - 1] * A[j]);
				mx[i][j] = max(max(mx[i][j - 1], mn[i - 1][j - 1] * A[j]), mx[i - 1][j - 1] * A[j]);
			}
		}

		ll ans = -(1LL << 60);
		for(int i = 5; i <= N; i++) ans = max(ans, mx[5][i]);
		printf("%lld\n", ans);
	}
	return 0;
}