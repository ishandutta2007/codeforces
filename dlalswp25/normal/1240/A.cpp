#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, T;
int P[202020];
ll K;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) { scanf("%d", &P[i]); P[i] /= 100; }
		int x, a, y, b; scanf("%d%d%d%d", &x, &a, &y, &b);
		scanf("%lld", &K);

		sort(P + 1, P + N + 1);
		reverse(P + 1, P + N + 1);

		ll s = 0, c = 0;

		int l = 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;

			ll s = 0, c = 1;
			for(int i = a; i <= m; i += a) {
				if(i % b == 0) {
					s += (ll)P[c] * (x + y); c++;
				}
			}

			if(x < y) {
				for(int i = b; i <= m; i += b) {
					if(i % a == 0) continue;
					s += (ll)P[c] * y; c++;
				}
				for(int i = a; i <= m; i += a) {
					if(i % b == 0) continue;
					s += (ll)P[c] * x; c++;
				}
			}
			else {
				for(int i = a; i <= m; i += a) {
					if(i % b == 0) continue;
					s += (ll)P[c] * x; c++;
				}
				for(int i = b; i <= m; i += b) {
					if(i % a == 0) continue;
					s += (ll)P[c] * y; c++;
				}
			}

			if(s >= K) r = m - 1;
			else l = m + 1;
		}
		if(l > N) puts("-1");
		else printf("%d\n", l);
	}
	return 0;
}