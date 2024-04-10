#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll X;
ll A[202020];
ll B[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i < N; i++) scanf("%lld", &B[i]);
		ll ans = 1LL << 60;
		ll d = 0, c = 0;
		for(int i = 1; i <= N; i++) {
			ll lft = X - c;
			if(lft < 0) { ans = min(ans, d); break; }

			ans = min(ans, d + (lft + A[i] - 1) / A[i]);

			if(i == N) break;
			if(c >= B[i]) c -= B[i];
			else {
				ll t = (B[i] - c + A[i] - 1) / A[i];
				c += A[i] * t;
				d += t;
				c -= B[i];
			}
			d++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}