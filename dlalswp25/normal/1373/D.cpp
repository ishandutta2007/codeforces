#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

int N;
ll A[202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		ll sum = 0;
		for(int i = 0; i < N; i++) {
			scanf("%lld", &A[i]);
			if(i % 2 == 0) sum += A[i];
		}

		ll ans = -INF;

		ll mn = 0, s = 0;
		for(int i = 0; i + 1 < N; i += 2) {
			s += (A[i + 1] - A[i]);
			ans = max(ans, (s - mn));
			mn = min(mn, s);
		}

		mn = -A[0]; s = -A[0];
		for(int i = 1; i + 1 < N; i += 2) {
			s += (A[i] - A[i + 1]);
			ans = max(ans, (s - mn));
			mn = min(mn, s);
		}
		printf("%lld\n", sum + max(0LL, ans));
	}
	return 0;
}