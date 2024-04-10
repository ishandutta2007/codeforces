#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int X = *min_element(A + 1, A + N + 1);
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			ans += (A[i] - 1) / (X + X - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}