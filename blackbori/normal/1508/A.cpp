#include <bits/stdc++.h>

using namespace std;

void tc() {
	string A, B, C;
	int n;
	int a, b, c, i, ai, bi;
	cin >> n >> A >> B >> C;

	a = b = c = 0;
	for (i = 0; i < n + n; i++) {
		a += A[i] == '1';
		b += B[i] == '1';
		c += C[i] == '1';
	}

	if (a < b) swap(a, b), swap(A, B);
	if (a < c) swap(a, c), swap(A, C);
	if (b < c) swap(b, c), swap(B, C);

	string S;
	if (a >= n && b >= n) {
		ai = bi = 0;
		for (i = 1; i <= n; i++) {
			for (; A[ai] == '0'; ai++) {
				S.push_back(A[ai]);
			}
			ai++;

			for (; B[bi] == '0'; bi++) {
				S.push_back(B[bi]);
			}
			bi++;

			S.push_back('1');
		}
		for (; ai < n + n; ai++) {
			S.push_back(A[ai]);
		}
		for (; bi < n + n; bi++) {
			S.push_back(B[bi]);
		}
	}
	else {
		// b <= n && c <= n
		swap(A, C);
		ai = bi = 0;
		for (i = 1; i <= n; i++) {
			for (; A[ai] == '1'; ai++) {
				S.push_back(A[ai]);
			}
			ai++;

			for (; B[bi] == '1'; bi++) {
				S.push_back(B[bi]);
			}
			bi++;

			S.push_back('0');
		}
		for (; ai < n + n; ai++) {
			S.push_back(A[ai]);
		}
		for (; bi < n + n; bi++) {
			S.push_back(B[bi]);
		}
	}
	cout << S << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}