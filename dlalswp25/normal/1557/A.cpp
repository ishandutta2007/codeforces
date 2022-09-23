#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[101010];
ll S[101010];
double ans;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		sort(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

		ans = -1e18;
		for(int i = 1; i < N; i++) {
			ans = max(ans, (double)S[i] / i + (double)(S[N] - S[i]) / (N - i));
		}
		printf("%.10f\n", ans);
	}
	return 0;
}