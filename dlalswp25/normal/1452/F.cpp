#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll C[35];
ll A[35];
int N, Q;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 0; i < N; i++) scanf("%lld", &C[i]);
	while(Q--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int p, v; scanf("%d%d", &p, &v);
			C[p] = v;
		}
		else {
			int x; ll k; scanf("%d%lld", &x, &k);
			for(int i = 0; i < N; i++) A[i] = C[i];
			ll s = 0;
			for(int i = 0; i <= x; i++) s += (1LL << i) * C[i];
			ll ans = 0;
			if(s < k) {
				for(int i = x + 1; i < N; i++) {
					if(s + A[i] * (1LL << i) < k) {
						s += A[i] * (1LL << i);
						ans += A[i] * ((1LL << i - x) - 1);
						A[x] += A[i] * (1LL << i - x);
						A[i] = 0;
						continue;
					}
					ll b = 1LL << i;
					ll q = (k - s) / b;
					ans += q * ((1LL << i - x) - 1);
					A[i] -= q;
					A[x] += q * (1LL << i - x);
					s += q * b;

					if(s < k) {
						A[i]--;
						for(int j = i - 1; j > x; j--) A[j] = 1;
						A[x] += 2;
						s += 1LL << x + 1;
						ans += i - x;
						if(s >= k) break;
						ll lft = k - s;
						ll r = lft % (1LL << x + 1);
						if(r) lft += ((1LL << x + 1) - r);

						// printf("%lld\n", lft);
						// printf("%lld\n", ans);
						for(int j = i - 1; j > x; j--) {
							if(lft >= 1LL << j) {
								A[j] = 0;
								A[x] += 1LL << j - x;
								ans += ((1LL << j - x) - 1);
								lft -= 1LL << j;
							}
						}
						s = k;
					}

					break;
				}

				if(s < k) { puts("-1"); continue; }
			}

			// for(int i = 0; i < N; i++) printf("%lld ", A[i]); puts("");

			ll cnt = 0;
			for(int i = 0; i <= x; i++) cnt += A[i];
			for(int i = x + 1; i < N; i++) {
				if(cnt >= k) break;
				ll lft = k - cnt;
				ll b = 1LL << i - x;
				if(b * A[i] < lft) {
					ans += A[i] * (b - 1);
					cnt += b * A[i];
					A[x] += A[i] * b;
					A[i] = 0;
					continue;
				}

				ll q = lft / b;
				ans += q * (b - 1);
				cnt += q * b;
				A[x] += q * b;
				A[i] -= q;
				lft -= q * b;
				
				ans += lft; cnt = k;

				break;
			}
			printf("%lld\n", ans + max(0LL, k - cnt));
		}
	}
	return 0;
}