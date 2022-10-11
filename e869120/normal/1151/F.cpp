#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 109;
long long inv[10009], mod = 1000000007;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 60; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

void init() {
	for (int i = 0; i <= 10000; i++) inv[i] = modpow(i, mod - 2, mod);
}

long long Fraction(long long a, long long b) {
	return (a * inv[b]) % mod;
}

struct Matrix {
	long long a[MAX_N][MAX_N];
};

void init(Matrix &A1) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) A1.a[i][j] = 0;
	}
}

Matrix Mul(Matrix A1, Matrix A2) {
	Matrix A3; init(A3);
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			for (int k = 0; k < MAX_N; k++) {
				A3.a[i][k] += A1.a[i][j] * A2.a[j][k];
				A3.a[i][k] %= mod;
			}
		}
	}
	return A3;
}

Matrix modpows(Matrix A1, long long K) {
	Matrix A2; init(A2);
	for (int i = 0; i < MAX_N; i++) A2.a[i][i] = 1;

	for (int i = 0; i < 30; i++) {
		if ((K / (1LL << i)) % 2 == 1) { A2 = Mul(A2, A1); }
		A1 = Mul(A1, A1);
	}
	return A2;
}

long long N, K, I1[109], I2[109], A1, A2;

int main() {
	init();
	cin >> N >> K;
	for (int i = 0; i < N; i++) { cin >> I1[i]; I2[i] = I1[i]; if (I1[i] == 0) A1++; if (I2[i] == 1) A2++; }
	sort(I2, I2 + N);

	Matrix J; init(J);
	for (int i = 0; i <= min(A1, A2) * 2; i += 2) {
		long long E1 = (i / 2) * (i / 2);
		long long E3 = (A1 - (i / 2)) * (A2 - (i / 2));
		long long E2 = N * (N - 1) / 2 - E1 - E3;

		if (E3 >= 1) J.a[i + 2][i + 0] = Fraction(E3, E1 + E2 + E3);
		if (E2 >= 1) J.a[i + 0][i + 0] = Fraction(E2, E1 + E2 + E3);
		if (E1 >= 1) J.a[i - 2][i - 0] = Fraction(E1, E1 + E2 + E3);
	}
	int cnt = 0; long long ans = 0;
	for (int i = 0; i < N; i++) { if (I1[i] != I2[i]) cnt++; }

	Matrix L = modpows(J, K);
	cout << L.a[0][cnt] << endl;
	return 0;
}