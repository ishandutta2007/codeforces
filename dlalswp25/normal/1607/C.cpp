#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		ll ans = A[1];
		for(int i = 2; i <= N; i++) ans = max(ans, (ll)A[i] - A[i - 1]);
		printf("%lld\n", ans);
	}
	return 0;
}