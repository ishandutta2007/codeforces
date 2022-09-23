#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[303030];
int S[303030];

int cnt[1050505][2];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] ^ A[i];

	cnt[0][0] = 1;
	for(int i = 1; i <= N; i++) {
		cnt[S[i]][i & 1]++;
	}
	ll ans = 0;
	for(int i = 0; i < 1050505; i++) {
		ans += (ll)cnt[i][0] * (cnt[i][0] - 1) / 2;
		ans += (ll)cnt[i][1] * (cnt[i][1] - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}