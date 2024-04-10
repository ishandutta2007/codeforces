#include <bits/stdc++.h>

using namespace std;

void tc() {
	string S, T;
	int n, i, s;
	cin >> n >> S;
	T = S; sort(T.begin(), T.end());
	for (i = s = 0; i < n; i++) {
		if (S[i] != T[i]) s++;
	}
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; tc());
	
	return 0;
}