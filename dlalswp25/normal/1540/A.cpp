#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		sort(A + 1, A + N + 1);
		ll ans = A[N];
		ll s = A[1];
		for(int i = 2; i <= N; i++) {
			ll t = (i - 1) * A[i] - s;
			ans -= t;
			s += A[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}