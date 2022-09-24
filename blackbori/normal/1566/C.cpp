#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, i, s, f;
	string A, B;
	cin >> n >> A >> B;
	for (i = s = f = 0; i < n; i++) {
		if (A[i] != B[i]) s += 2;
		else if (A[i] == '0') {
			s++;
			if (i >= 1 && A[i - 1] == '1' && B[i - 1] == '1' && !f) s++, f = 1;
			else f = 0;
		}
		else {
			if (i >= 1 && A[i - 1] == '0' && B[i - 1] == '0' && !f) s++, f = 1;
			else f = 0;
		}
	}
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;

	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}