#include <bits/stdc++.h>

using namespace std;

int A[1010101], S[1010101];
int n, c;

void tc() {
	int i, j, l;
	cin >> n >> c;
	for (i = 1; i <= c; i++) {
		S[i] = 0;
	}
	for (i = 1; i <= n; i++) {
		cin >> A[i]; S[A[i]]++;
	}
	for (i = 1; i <= c; i++) {
		S[i] += S[i - 1];
	}
	for (i = 1; i <= c; i++) if (S[i] == S[i - 1]) {
		for (j = i, l = 1; j <= c; j += i, l++) {
			if (S[l] > S[l - 1] && S[min(c, j + l - 1)] - S[j - 1]) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}