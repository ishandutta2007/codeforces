#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;

int N, T;
double P[5005], Q[5005];
int L[5005];
double A[5005][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> T;
	for(int n = 0; n < N; ++n) {
		cin >> P[n] >> L[n];
		P[n] /= 100.0;
		Q[n] = 1 - P[n];
	}
	
	for(int n = N - 1; n >= 0; --n) {
		double Qk = pow(Q[n], L[n] - 1);
		for(int t = 1; t < L[n]; ++t)
			A[n][t] = A[n][t - 1] * Q[n] + P[n] * (1 + A[n + 1][t - 1]);
		A[n][L[n]] = A[n][L[n] - 1] * Q[n] - P[n] * Qk + Qk + P[n] * (1 + A[n + 1][L[n] - 1]);
		for(int t = L[n] + 1; t <= T; ++t)
			A[n][t] = A[n][t - 1] * Q[n] - P[n] * Qk * (1 + A[n + 1][t - L[n]]) - Q[n] * Qk * (1 + A[n + 1][t - L[n] - 1])
				+ Qk * (1 + A[n + 1][t - L[n]]) + P[n] * (1 + A[n + 1][t - 1]);
	}
	
	cout << setprecision(10) << A[0][T];
}