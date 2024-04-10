#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[40404];
int S[40404];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, q; scanf("%d%d%d", &a, &b, &q);
		for(int i = 0; i < a * b; i++) {
			if(i % a % b != i % b % a) A[i] = 1;
			else A[i] = 0;
			if(i == 0) S[i] = A[i];
			else S[i] = S[i - 1] + A[i];
		}
		while(q--) {
			ll l, r; scanf("%lld%lld", &l, &r);
			ll lq = l / (a * b);
			ll rq = r / (a * b);
			ll lr = l % (a * b);
			ll rr = r % (a * b);

			ll ans = 0;

			if(lq == rq) {
				ll tmp = (lr == 0 ? 0 : S[lr - 1]);
				ans += S[rr] - tmp;
			}
			else {
				ans += (rq - lq - 1) * S[a * b - 1];
				ans += S[rr];
				ans += S[a * b - 1] - (lr == 0 ? 0 : S[lr - 1]);
			}
			printf("%lld ", ans);
		}
		puts("");
	}
	return 0;
}