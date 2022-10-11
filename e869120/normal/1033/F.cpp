#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning (disable: 4996)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int W, N, M, A[1 << 12], t[550000], power[13];
int u[2][128], bit[1 << 12][12]; string str;

void init() {
	power[W - 1] = 1; for (int i = W - 2; i >= 0; i--) power[i] = power[i + 1] * 3;
	for (int i = 0; i < (1 << W); i++) {
		for (int j = 0; j < (1 << W); j++) {
			int rem = 0, v = 1;
			for (int k = 0; k < W; k++) {
				int p1 = 1; if ((i&(1 << k)) == 0) p1 = 0;
				int p2 = 1; if ((j&(1 << k)) == 0) p2 = 0;
				if (p2 == 1) { rem += 2 * v; }
				else rem += p1 * v;
				v *= 3;
			}
			t[rem] += A[i];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 128; j++) {
			if (j == 'A') { if (i == 0) u[i][j] = 2; else u[i][j] = 0; }
			if (j == 'O') { if (i == 0) u[i][j] = 0; else u[i][j] = 3; }
			if (j == 'X') { if (i == 0) u[i][j] = 0; else u[i][j] = 1; }
			if (j == 'a') { if (i == 0) u[i][j] = 3; else u[i][j] = 1; }
			if (j == 'o') { if (i == 0) u[i][j] = 1; else u[i][j] = 2; }
			if (j == 'x') { if (i == 0) u[i][j] = 1; else u[i][j] = 0; }
		}
	}
	for (int i = 0; i < (1 << W); i++) {
		for (int j = 0; j < W; j++) bit[i][j] = (i / (1 << (W - 1 - j))) % 2;
	}
}

int query(int pos) {
	if (A[pos] == 0) return 0;
	int sum = 0;
	for (int i = 0; i < W; i++) {
		int Z = u[bit[pos][i]][str[i]]; if (Z == 3) return 0;
		sum += Z * power[i];
	}
	return t[sum];
}

int main() {
	scanf("%d%d%d", &W, &N, &M);
	for (int i = 0; i < N; i++) { int C; scanf("%d", &C); A[C]++; }
	init();
	for (int i = 0; i < M; i++) {
		cin >> str;
		int sum = 0;
		for (int j = 0; j < (1 << W); j++) sum += A[j] * query(j);
		printf("%d\n", sum);
	}
	return 0;
}