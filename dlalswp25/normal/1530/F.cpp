#include <bits/stdc++.h>

using namespace std;
const int MOD = 31607;

int N;
int A[25][25];
int I[25][25];
int R[25];
bool B[25][25];

int pw(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int inv(int x) { return pw(x, MOD - 2); }

void unchk(int i, int j) {
	if(!B[i][j]) return;
	B[i][j] = false;
	R[i] = R[i] * A[i][j] % MOD;
}

void chk(int i, int j) {
	if(B[i][j]) return;
	B[i][j] = true;
	R[i] = R[i] * I[i][j] % MOD;
}

int g() {
	int ret = 1;
	for(int i = 1; i <= N; i++) {
		ret = ret * (1 + MOD - R[i]) % MOD;
	}
	return ret;
}

int f(int j) {
	if(j > N) {
		// for(int i = 1; i <= N; i++) {
		// 	for(int k = 1; k <= N; k++) {
		// 		printf("%d", B[i][k]);
		// 	}
		// 	puts("");
		// }
		// for(int i = 1; i <= N; i++) printf("r %d\n", R[i]);
		int ret = g();
		// printf("%d\n", ret);
		return ret;
	}
	int ret = f(j + 1);
	int p = 1;
	vector<int> v;
	for(int i = 1; i <= N; i++) {
		if(!B[i][j]) {
			p = p * A[i][j] % MOD;
			chk(i, j);
			v.push_back(i);
		}
	}
	ret = (ret + MOD - p * f(j + 1) % MOD) % MOD;
	for(int i : v) unchk(i, j);
	return ret;
}

int main() {
	const int I10000 = inv(10000);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			A[i][j] = A[i][j] * I10000 % MOD;
			I[i][j] = inv(A[i][j]);
		}
	}

	int ans = 0;

	for(int z = 0; z < 4; z++) {
		for(int i = 1; i <= N; i++) {
			R[i] = 1;
			for(int j = 1; j <= N; j++) {
				R[i] = R[i] * A[i][j] % MOD;
				B[i][j] = false;
			}
		}

		int t = 1;
		int p = 1;
		if(z & 1) {
			t *= -1;
			for(int i = 1; i <= N; i++) {
				if(!B[i][i]) p = p * A[i][i] % MOD;
				chk(i, i);
			}
		}
		if(z & 2) {
			t *= -1;
			for(int i = 1; i <= N; i++) {
				if(!B[N - i + 1][i]) p = p * A[N - i + 1][i] % MOD;
				chk(N - i + 1, i);
			}
		}

		int add = f(1);
		// printf("%d %d %d\n", z, p, add);

		ans = (ans + MOD + t * (p * add % MOD)) % MOD;
	}

	printf("%d\n", (1 + MOD - ans) % MOD);

	return 0;
}