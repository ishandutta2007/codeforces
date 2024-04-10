#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int N;
pii A[202020];
ll S[202020];
bool chk[202020];

int main() {
	scanf("%d", &N);
	ll s = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i].first);
		A[i].second = i;
	}
	if(N == 1) { printf("%lld\n", A[1].first); return 0; }

	sort(A + 1, A + N + 1);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i].first;

	int r = (300004 - N) % 3;
	ll ans = -(1LL << 60);

	int j = 1;
	for(int i = r; i <= N; i += 3) {
		for(; j <= i; j++) chk[A[j].second] = true;

		if(i == N / 2) {
			bool f = false;
			for(int k = 2; k <= N; k++) if(chk[k] == chk[k - 1]) f = true;
			if(f) ans = max(ans, S[N] - S[i] * 2);
			else {
				ans = max(ans, S[N] - (S[i] - A[i].first + A[i + 1].first) * 2);
			}
		}
		else ans = max(ans, S[N] - S[i] * 2);
	}
	printf("%lld\n", ans);

	return 0;
}