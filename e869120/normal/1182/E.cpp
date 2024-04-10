#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const long long mod1 = 1000000006;
const long long mod = 1000000007;

struct Matrix {
	long long a[5][5];
};

void init(Matrix &P) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) P.a[i][j] = 0;
	}
}

Matrix Mul(Matrix G1, Matrix G2) {
	Matrix G3; init(G3);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				G3.a[i][j] += G1.a[i][k] * G2.a[k][j];
				G3.a[i][j] %= mod1;
			}
		}
	}
	return G3;
}

Matrix Power(Matrix A1, long long K) {
	Matrix A2; init(A2); for (int i = 0; i < 5; i++) A2.a[i][i] = 1;
	for (int i = 0; i < 62; i++) {
		if ((K / (1LL << i)) % 2 == 1) {
			A2 = Mul(A2, A1);
		}
		A1 = Mul(A1, A1);
	}
	return A2;
}

long long calc(vector<long long>A, long long P) {
	if (P < 0) return 0;
	if (P < A.size()) return A[P];
	Matrix E; init(E);
	for (int i = 0; i < A.size() - 1; i++) E.a[i][i + 1] = 1;
	for (int i = 0; i < A.size(); i++) E.a[A.size() - 1][i] = 1;

	E = Power(E, P);
	long long S = 0; for (int i = 0; i < A.size(); i++) S += E.a[0][i] * A[i];
	return S % mod1;
}

long long modpow(long long a, long long b, long long m) {
	a %= m;
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

int main() {
	long long N, F1, F2, F3, K;
	cin >> N >> F1 >> F2 >> F3 >> K;

	long long E1 = calc(vector<long long>{1, 1, 2}, N - 4);
	long long E2 = calc(vector<long long>{1, 2, 3}, N - 4);
	long long E3 = calc(vector<long long>{1, 2, 4}, N - 4);
	long long E4 = calc(vector<long long>{1, 2, 3}, N - 1) - N + 3LL * mod1 * mod1; E4 %= mod1;

	long long ret = 1;
	long long G1 = modpow(F1, E1, mod); ret *= G1; ret %= mod;
	long long G2 = modpow(F2, E2, mod); ret *= G2; ret %= mod;
	long long G3 = modpow(F3, E3, mod); ret *= G3; ret %= mod;
	long long G4 = modpow(K, E4, mod); ret *= G4; ret %= mod;
	cout << ret << endl;
	return 0;
}