#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int ans = 1;

		for(int i = 1; i < N; i++) {
			if(A[i] == A[i - 1]) continue;
			ll x = A[i], y = A[i + 1];
			int p = i + 2;
			int cnt = 2;
			while(1) {
				int t = lower_bound(A + p, A + N + 1, 2 * y - x) - A;
				if(t > N) break;
				cnt++; y = A[t]; p = t + 1;
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", N - ans);
	}
	return 0;
}