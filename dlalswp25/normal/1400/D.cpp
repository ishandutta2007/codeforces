#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[3030];
ll cnt[3030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll ans = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) cnt[i] = 0;

		for(int i = N; i >= 1; i--) {
			ll t = 0;
			if(i < N) {
				for(int j = i - 1; j >= 1; j--) {
					if(A[i] == A[j]) ans += t;
					t += cnt[A[j]];
				}
			}
			cnt[A[i]]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}