#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		ll s = 0;
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			s += x;
		}
		printf("%lld\n", (s % N) * (N - s % N));
	}
	return 0;
}