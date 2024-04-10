#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, X;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ll ans = 0;
		for(int i = 2; i <= N; i++) ans += abs(A[i] - A[i - 1]);
		int mn = *min_element(A + 1, A + N + 1), mx = *max_element(A + 1, A + N + 1);
		if(mn > 1) ans += min(2 * (mn - 1), min(A[1], A[N]) - 1);
		if(mx < X) ans += min(2 * (X - mx), X - max(A[1], A[N]));
		printf("%lld\n", ans);
	}
	return 0;
}