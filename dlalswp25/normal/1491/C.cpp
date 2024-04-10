#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[5050];
ll B[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) B[i] = 0;
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			ans += max(0LL, (A[i] - 1 - B[i]));
			for(int j = min(N, i + A[i]); j > i + 1; j--) {
				B[j]++;
			}
			ll t = B[i] - (A[i] - 1);
			if(t > 0) B[i + 1] += t;
		}
		printf("%lld\n", ans);
	}
	return 0;
}