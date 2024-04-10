#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];

ll calc(int x) {
	ll ret = 0;
	int c = 0;
	for(int i = 1; i <= N; i++) {
		if(A[i]) {
			c++;
			ret += abs((2 * c - x) - i);
		}
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int one = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			A[i] &= 1;
			if(A[i]) one++;
		}

		ll ans = 0;
		if(N & 1) {
			if(one != N / 2 && one != (N + 1) / 2) { puts("-1"); continue; }

			if(one == N / 2) ans = calc(0);
			else ans = calc(1);
		}
		else {
			if(one != N / 2) { puts("-1"); continue; }
			ans = min(calc(0), calc(1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}