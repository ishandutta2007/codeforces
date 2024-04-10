#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
ll A[303030];
ll B[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i <= M; i++) scanf("%lld", &B[i]);
		sort(A + 1, A + N + 1);
		ll ans = 0;
		int x = 1;
		for(int i = N; i >= 1; i--) {
			if(x > A[i]) ans += B[A[i]];
			else { ans += B[x]; x++; }
		}
		printf("%lld\n", ans);
	}
	return 0;
}