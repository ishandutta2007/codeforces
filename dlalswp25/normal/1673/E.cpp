#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 1 << 20;

int N, K;
int B[1050505];
bool ans[1050505];
int T[1050505];
int S[25][1050505];

bool ncr(int n, int r) {
	if(n < r) return 0;
	return T[n] == T[r] + T[n - r];
}

int main() {
	scanf("%d%d", &N, &K); K = (N - 1) - K;
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	for(int i = 1; i <= N; i++) {
		int tmp = i, cnt = 0;
		while(tmp) {
			if(~tmp & 1) cnt++;
			else break;
			tmp >>= 1;
		}
		T[i] = T[i - 1] + cnt;
	}
	for(int i = 1; i <= min(N, 22); i++) {
		for(int j = 0; j <= N; j++) {
			if(j) S[i][j] = S[i][j - 1];
			S[i][j] ^= ncr(N - i, j);
		}
	}
	for(int i = 1; i <= N; i++) {
		ll t = B[i];
		int r = i;
		while(r <= N) {
			if(r - i > K) break;
			int n = 1 + (r - i) + (i > 1) + (r < N);
			int k = K - (r - i);
			ans[t] ^= S[n][k];
			r++;
			if(r > N || B[r] >= 20 || t * (1 << B[r]) >= MX) break;
			t *= 1 << B[r];
		}
	}

	bool z = true;
	for(int i = MX - 1; i >= 0; i--) {
		if(ans[i]) z = false;
		if(!z) printf("%d", ans[i]);
	}
	if(z) printf("0");
	puts("");
	return 0;
}