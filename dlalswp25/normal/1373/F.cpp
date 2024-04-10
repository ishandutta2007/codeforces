#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

ll A[1010101];
ll B[1010101];

ll sb[2020202];
ll sa[2020202];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);

		ll mxa = -INF;
		for(int i = 1; i <= N; i++) sb[i] = sb[i - 1] + (B[i] - A[i]);
		for(int i = 1; i <= N; i++) {
			sa[i] = sa[i - 1] + (B[i - 1] - A[i]);
			mxa = max(mxa, sa[i]);
		}

		bool ok = true;
		for(int i = N + 1; i <= 2 * N; i++) {
			sb[i] = sb[i - 1] + (B[i - N] - A[i - N]);
			sa[i] = sa[i - 1] + ((i == N + 1 ? B[N] : B[i - N - 1]) - A[i - N]);
			mxa = max(mxa, sa[i]);
			if(sb[i] - mxa < 0) ok = false;
		}

		if(sb[N] < 0) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}