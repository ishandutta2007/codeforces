#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

long long N, M, A[20009];
long long p1[20009];

int main() {
	cin >> N >> M;

	long long r = M; A[1] = 1; A[2] = 2;
	if (N <= 2) {
		if (M != 0) { cout << "-1" << endl; return 0; }
		for (int j = 1; j <= N; j++) {
			if (j >= 2) cout << " ";
			cout << A[j];
		}
		cout << endl;
		return 0;
	}

	for (int i = 3; i <= N; i++) {
		long long cand = (i - 1) / 2;
		if (cand >= r) {
			for (int j = 1; j <= i - 1; j++) {
				for (int k = j + 1; k <= i - 1; k++) p1[A[j] + A[k]]++;
			}
			for (int j = A[i - 1] + 1; j <= 20000; j++) {
				if (p1[j] == r) { A[i] = j; break; }
			}

			// Naan
			for (int j = i + 1; j <= N; j++) {
				A[j] = 1000000000LL - 7000LL * (N - j);
			}

			// Output
			for (int j = 1; j <= N; j++) {
				if (j >= 2) cout << " ";
				cout << A[j];
			}
			cout << endl;
			return 0;
		}
		else {
			A[i] = i;
			r -= cand;
		}
	}

	cout << "-1" << endl;
	return 0;
}