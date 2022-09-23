#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[505050];
ll S[505050];

int R[505050];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= (N + 1) / 2; i++) scanf("%lld", &A[i]);
	ll x; scanf("%lld", &x);
	for(int i = (N + 1) / 2 + 1; i <= N; i++) A[i] = x;

	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
	if(S[N] > 0) { printf("%d\n", N); return 0; }
	if(x >= 0) { puts("-1"); return 0; }

	int M = (N + 1) / 2;

	bool ok = true;
	for(int i = M; i <= N; i++) {
		if(S[i] - S[i - M] <= 0) ok = false;
	}
	if(ok) { printf("%d\n", M); return 0; }

	for(int i = 0; i < M; i++) {
		int l = 1, r = (N - M);
		while(l <= r) {
			int m = l + r >> 1;
			if(S[M] + x * m <= S[i]) r = m - 1;
			else l = m + 1;
		}
		R[i] = r + M;
	}

	// for(int i = 0; i < M; i++) printf("%d ", R[i]); puts("");

	for(int i = 1; i < M; i++) R[i] = min(R[i], R[i - 1] + 1);

	for(int i = 0; i < M; i++) {
		if(R[i] == N) {
			printf("%d\n", N - i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}