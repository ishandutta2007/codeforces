#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A, B, K;
int ca[202020];
int cb[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &A, &B, &K);
		for(int i = 1; i <= A; i++) ca[i] = 0;
		for(int i = 1; i <= B; i++) cb[i] = 0;
		for(int i = 1; i <= K; i++) { int x; scanf("%d", &x); ca[x]++; }
		for(int i = 1; i <= K; i++) { int x; scanf("%d", &x); cb[x]++; }

		ll t = 0;
		for(int i = 1; i <= A; i++) {
			t += (ll)ca[i] * (ca[i] - 1) / 2;
		}
		for(int i = 1; i <= B; i++) {
			t += (ll)cb[i] * (cb[i] - 1) / 2;
		}
		printf("%lld\n", (ll)K * (K - 1) / 2 - t);
	}
	return 0;
}