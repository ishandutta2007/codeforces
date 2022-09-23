#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q, C;
ll mx[1010101];
ll D[1010101];

int main() {
	scanf("%d%d", &N, &C);
	for(int i = 1; i <= N; i++) {
		int c, d, h; scanf("%d%d%d", &c, &d, &h);
		mx[c] = max(mx[c], (ll)d * h);
	}
	for(int i = 1; i <= C; i++) {
		int t = 1;
		for(int j = i; j <= C; j += i) {
			D[j] = max(D[j], mx[i] * t - 1);
			t++;
		}
	}
	for(int i = 1; i <= C; i++) D[i] = max(D[i], D[i - 1]);

	scanf("%d", &Q);
	while(Q--) {
		ll d, h; scanf("%lld%lld", &d, &h);
		ll x = d * h;
		int l = 1, r = C;
		while(l <= r) {
			int m = l + r >> 1;
			if(D[m] >= x) r = m - 1;
			else l = m + 1;
		}
		if(l > C) printf("-1 ");
		else printf("%d ", l);
	}
	puts("");
	return 0;
}