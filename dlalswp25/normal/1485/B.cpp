#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q, K;
ll A[101010];
ll S[101010];

int main() {
	scanf("%d%d%d", &N, &Q, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) {
		ll t = (i == 1 || i == N ? 0 : A[i + 1] - A[i - 1] - 2);
		S[i] = S[i - 1] + t;
	}
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		if(l == r) printf("%d\n", K - 1);
		else if(l + 1 == r) printf("%lld\n", (A[r] - 2) + (K - A[l] - 1));
		else {
			ll ans = (A[l + 1] - 2) + (K - A[r - 1] - 1);
			ans += S[r - 1] - S[l];
			printf("%lld\n", ans);
		}
	}
	return 0;
}