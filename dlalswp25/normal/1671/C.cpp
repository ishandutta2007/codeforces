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
		sort(A + 1, A + N + 1);
		ll ans = 0, s = 0;
		for(int i = 1; i <= N; i++) {
			s += A[i];
			if(s > X) break;
			ans += (X - s) / i + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}