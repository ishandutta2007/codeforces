#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[20];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			while(A[i] % 2 == 0) {
				A[i] >>= 1; cnt++;
			}
		}
		sort(A + 1, A + N + 1);
		ll ans = 0;
		for(int i = 1; i < N; i++) ans += A[i];
		ll t = A[N];
		for(int i = 0; i < cnt; i++) t <<= 1;
		printf("%lld\n", ans + t);
	}
	return 0;
}