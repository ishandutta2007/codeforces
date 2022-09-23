#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1010101010;

ll A[101010];
ll B[101010];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	ll ans = 0;
	for(int i = -30; i <= 30; i++) {
		for(int j = 1; j <= N; j++) {
			if(A[j] > i) B[j] = -INF;
			else B[j] = A[j];
		}

		ll tmp = -INF;
		ll bef = 0;
		for(int j = 1; j <= N; j++) {
			ll x = max(0LL, bef) + B[j];
			tmp = max(tmp, x);
			bef = x;
		}
		ans = max(ans, tmp - i);
	}
	printf("%lld\n", ans);
	return 0;
}