#include <bits/stdc++.h>

using namespace std;

int A[101010];

void tc() {
	int n, m, i, a, b;
	cin >> n; a = b = 0;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] == 0) b++;
	}
	m = n;
	m = min(m, max(a, b));
	for (i = 1; i <= n; i++) {
		if (A[i] == 1) a++;
		else b--;
		m = min(m, max(a, b));
	}
	cout << m << "\n";
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