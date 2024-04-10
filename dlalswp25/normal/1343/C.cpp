#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[202020];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		int p = 1;

		ll ans = 0;
		while(p <= N) {
			ll t = -1010101010;
			do {
				t = max(t, A[p]);
				p++;
			}while(p <= N && (A[p] > 0) == (A[p - 1] > 0));

			ans += t;
		}
		printf("%lld\n", ans);
	}
	return 0;
}