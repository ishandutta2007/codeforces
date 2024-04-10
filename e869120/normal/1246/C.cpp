#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long H, W;
char c[2009][2009];

// 1 : 2 : 
long long mod = 1000000007;
long long dp1[2009][2009], dp2[2009][2009];
long long r1[2009][2009], r2[2009][2009];
long long v1[2009][2009], v2[2009][2009];

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) scanf("%s", &c[i]);

	if (H == 1 && W == 1) {
		cout << "1" << endl;
		return 0;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j <= 2000; j++) v1[i][j] = -1;

		long long cnt = 0;
		for (int j = W - 1; j >= 0; j--) {
			if (c[i][j] == 'R') { cnt++; v1[i][cnt] = j; }
		}
	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j <= 2000; j++) v2[i][j] = -1;

		long long cnt = 0;
		for (int j = H - 1; j >= 0; j--) {
			if (c[j][i] == 'R') { cnt++; v2[i][cnt] = j; }
		}
	}

	// 
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i == 3 && j == 1) {
				i += 0;
			}
			
			//  DP 
			if (i == 0 && j == 0) {
				dp1[i][j] = 1; dp2[i][j] = 1;
			}
			else {
				// 
				if (j >= 1) {
					long long L1 = v1[i][W - j];
					dp2[i][j] = r1[i][j - 1];
					if (L1 >= 1) dp2[i][j] -= r1[i][L1 - 1];
					dp2[i][j] += mod; dp2[i][j] %= mod;
				}

				// 
				if (i >= 1) {
					long long L2 = v2[j][H - i];
					dp1[i][j] = r2[i - 1][j];
					if (L2 >= 1) dp1[i][j] -= r2[L2 - 1][j];
					dp1[i][j] += mod; dp1[i][j] %= mod;
				}
			}

			// 
			r1[i][j] = (r1[i][j - 1] + dp1[i][j]) % mod;
			r2[i][j] = (r2[i - 1][j] + dp2[i][j]) % mod;
		}
	}

	cout << (dp1[H - 1][W - 1] + dp2[H - 1][W - 1]) % mod << endl;
	return 0;
}