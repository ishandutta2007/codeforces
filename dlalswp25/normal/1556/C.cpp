#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int C[1010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	ll ans = 0;

	for(int i = 1; i <= N; i += 2) {
		ll mn = 0, sum = 0;
		for(int j = i + 1; j <= N; j++) {
			if(j % 2 == 0) {
				ll lmn = max(1LL, -mn);
				ll rmn = max(1LL, sum + lmn);
				ans += max(0LL, min(C[i] - lmn + 1, C[j] - rmn + 1));
			}
			if(j & 1) sum += C[j];
			else sum -= C[j];
			mn = min(mn, sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}