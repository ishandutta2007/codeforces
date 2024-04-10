#include <bits/stdc++.h>

using namespace std;

const int p = 31607;
const int q = 3973;

int A[22][22], P[22][22];
int B[1 << 21], C[1 << 21], D[22][1 << 21];
int I[p];
int n;

int inv(int x) { return x > 1 ? inv(p % x) * (p - p / x) % p : 1; }

int solve(int s) {
	int i, j, t, a;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			s = s * I[P[i][j]] % p;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < 1 << n; j++) {
			if (j == 0) D[i][j] = 1;
			else D[i][j] = D[i][j - (1 << B[j])] * P[i][B[j]] % p;
		}
	}

	a = 0;
	for (i = 0; i < 1 << n; i++) {
		for (j = 0, t = 1; j < n; j++) {
			t = t * (1 + p - D[j][i]) % p;
		}
		if (C[i]) t = -t;
		if (t < 0) t += p;
		a = (a + s * t) % p;
	}
	return -a % p;
}

void tc() {
	int i, j, a, s;
	cin >> n; a = 0;

	for (i = 0; i < 1 << n; i++) {
		for (j = 0; j < n; j++) {
			if (i & 1 << j) C[i] ^= 1, B[i] = j;
		}
	}
	for (i = 1; i < p; i++) {
		I[i] = inv(i);	
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> A[i][j]; A[i][j] = A[i][j] * q % p;
			P[i][j] = I[A[i][j]];
		}
	}
	a += solve(1);

	for (i = 0; i < n; i++) P[i][i] = 1;
	for (i = 0, s = 1; i < n; i++) {
		s = s * A[i][i] % p;
	}
	a -= solve(s);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			P[i][j] = I[A[i][j]];
		}
		P[i][n - i - 1] = 1;
	}
	for (i = 0, s = 1; i < n; i++) {
		s = s * A[i][n - i - 1] % p;
	}
	a -= solve(s);

	for (i = 0; i < n; i++) P[i][i] = 1;
	for (i = 0, s = 1; i < n; i++) {
		s = s * A[i][i] % p;
		if (i != n - i - 1) s = s * A[i][n - i - 1] % p;
	}
	a += solve(s);

	cout << (a % p + p + 1) % p << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
//	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}