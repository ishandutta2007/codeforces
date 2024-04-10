#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[30];
int B[30];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		ll ans = 0;
		for(int i = 2; i <= N; i++) {
			ans += min(abs(A[i] - A[i - 1]) + abs(B[i] - B[i - 1]), abs(A[i] - B[i - 1]) + abs(B[i] - A[i - 1]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}