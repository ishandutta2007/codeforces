#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[70];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 70; i++) cnt[i] = 0;

		int N, K; scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) {
			ll x; scanf("%lld", &x);
			ll t = 1;
			int j = 0;
			while(t < x) { t *= K; j++; }
			for(; j >= 0; j--) {
				while(x >= t) {
					cnt[j]++;
					x -= t;
				}
				t /= K;
			}
		}

		bool ok = true;
		for(int i = 0; i < 70; i++) if(cnt[i] >= 2) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}