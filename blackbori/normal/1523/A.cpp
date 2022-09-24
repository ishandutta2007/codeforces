#include <bits/stdc++.h>

using namespace std;

string A, B;
int n, m;

void tc() {
	int i, j;
	cin >> n >> m >> A;
	for (i = 1; i <= m && i <= n + n; i++) {
		B = A;
		for (j = 0; j < n; j++) {
			if (A[j] == '0') {
				int c = 0;
				if (j + 1 < n && A[j + 1] == '1') c++;
				if (j - 1 >= 0 && A[j - 1] == '1') c++;
				if (c == 1) B[j] = '1';
				else B[j] = '0';
			}
			else B[j] = '1';
		}
		A = B;
	}
	cout << A << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}