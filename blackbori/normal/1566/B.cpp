#include <bits/stdc++.h>

using namespace std;

void solve() {
	string S;
	int n, i, f;
	
	cin >> S; n = S.size();
	for (i = 0; i < n; i++) {
		if (S[i] == '0') break;
	}
	if (i == n) {
		cout << "0\n";
		return;
	}

	f = 0;
	for (i = 0; i < n; i++) {
		if (f == 0 && S[i] == '0') f = 1;
		if (f == 1 && S[i] == '1') f = 2;
		if (f == 2 && S[i] == '0') f = 3;
	}
	if (f != 3) {
		cout << "1\n";
		return;
	}

	cout << "2\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;

	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}