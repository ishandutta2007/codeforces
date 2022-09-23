#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[404040];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		A[N + 1] = 0;
		ll ans = A[N];
		for(int i = 1; i <= N; i++) ans += abs(A[i] - A[i - 1]);
		for(int i = 1; i <= N; i++) {
			int t = min(A[i] - A[i - 1], A[i] - A[i + 1]);
			if(t < 0) continue;
			ans -= t; A[i] -= t;
		}
		printf("%lld\n", ans);
	}
	return 0;
}