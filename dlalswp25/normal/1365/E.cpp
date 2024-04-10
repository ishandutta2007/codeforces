#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[505];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j++) {
			for(int k = j; k <= N; k++) {
				ans = max(ans, A[i] | A[j] | A[k]);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}