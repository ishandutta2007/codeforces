#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[70];
ll N;
int M;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%lld%d", &N, &M);
		for(int i = 0; i < 64; i++) cnt[i] = 0;
		ll s = 0;
		for(int i = 1; i <= M; i++) {
			int a; scanf("%d", &a);
			int b = 0;
			s += a;
			while(a > 1) {
				b++; a >>= 1;
			}
			cnt[b]++;
		}
		if(s < N) { puts("-1"); continue; }

		int ans = 0;
		for(int i = 0; i < 63; i++) {
			if(N & (1LL << i)) {
				if(!cnt[i]) {
					int j;
					for(j = i + 1; j < 63; j++) {
						if(cnt[j]) break;
					}
					ans += (j - i);
					cnt[j]--;
					for(int k = j - 1; k >= i; k--) cnt[k]++;
					cnt[i]++;
				}
				cnt[i]--;
				cnt[i + 1] += cnt[i] / 2;
			}
			else {
				cnt[i + 1] += cnt[i] / 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}