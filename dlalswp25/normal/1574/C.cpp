#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
ll A[202020];
ll S;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		S += A[i];
	}
	sort(A + 1, A + N + 1);
	scanf("%d", &M);
	while(M--) {
		ll x, y; scanf("%lld%lld", &x, &y);
		int t = lower_bound(A + 1, A + N + 1, x) - A;
		ll ans = (t > N ? 1LL << 60 : max(0LL, y - (S - A[t])));
		t--;
		if(t) {
			ans = min(ans, x - A[t] + max(0LL, y - (S - A[t])));
		}
		printf("%lld\n", ans);
	}
	return 0;
}