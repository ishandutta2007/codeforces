#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long W[1 << 19], Q, A[1 << 19], B[1 << 19], C[1 << 19], last, cnts = 1;
long long par1[1 << 19][22], dp1[1 << 19][22];
long long par2[1 << 19][22], dp2[1 << 19][22];

void update(long long pos, long long x) {
	cnts++; W[cnts] = x;
	int tx = pos;
	for (int i = 21; i >= 0; i--) {
		if (dp1[tx][i] < x) tx = par1[tx][i];
	}
	par1[cnts][0] = pos; for (int i = 0; i <= 20; i++) par1[cnts][i + 1] = par1[par1[cnts][i]][i];
	dp1[cnts][0] = x; for (int i = 0; i <= 20; i++) dp1[cnts][i + 1] = max(dp1[cnts][i], dp1[par1[cnts][i]][i]);

	par2[cnts][0] = tx; for (int i = 0; i <= 20; i++) par2[cnts][i + 1] = par2[par2[cnts][i]][i];
	dp2[cnts][0] = W[tx]; for (int i = 0; i <= 20; i++) dp2[cnts][i + 1] = dp2[cnts][i] + dp2[par2[cnts][i]][i];
}

long long query(long long pos, long long w) {
	w -= W[pos]; if (w < 0) return 0;
	long long ans = 1; int cx = pos;
	for (int i = 21; i >= 0; i--) {
		if (par2[cx][i] >= 1 && dp2[cx][i] <= w) {
			ans += (1 << i);
			w -= dp2[cx][i];
			cx = par2[cx][i];
		}
	}
	return ans;
}

int main() {
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);

	for (int i = 1; i <= Q; i++) {
		B[i] ^= last; C[i] ^= last;
		if (A[i] == 1) update(B[i], C[i]);
		if (A[i] == 2) {
			last = query(B[i], C[i]);
			printf("%lld\n", last);
		}
	}
	return 0;
}