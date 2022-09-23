#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 10000;

int N;
int A[105];
int B[105];
int D[2][10101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		ll ans = 0;
		for(int i = 1; i <= N; i++) ans += (N - 2) * A[i] * A[i];
		for(int i = 1; i <= N; i++) ans += (N - 2) * B[i] * B[i];

		int tot = 0;
		for(int i = 1; i <= N; i++) tot += (A[i] + B[i]);

		for(int i = 0; i < 2; i++) for(int j = 0; j <= MX; j++) D[i][j] = 0;
		D[0][0] = 1;
		for(int i = 1; i <= N; i++) {
			for(int j = MX; j >= 0; j--) {
				if(j >= A[i] && D[i + 1 & 1][j - A[i]]) D[i & 1][j] = 1;
				else if(j >= B[i] && D[i + 1 & 1][j - B[i]]) D[i & 1][j] = 1;
				else D[i & 1][j] = 0;
			}
		}

		ll mn = 1LL << 60;
		for(int i = 0; i <= MX; i++) {
			if(!D[N & 1][i]) continue;
			mn = min(mn, (ll)i * i + (ll)(tot - i) * (tot - i));
		}
		printf("%lld\n", ans + mn);
	}
	return 0;
}