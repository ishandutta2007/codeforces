#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, s, k;
	cin >> n >> s;
	k = (n + 1) / 2;
	cout << s / (n - k + 1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;

	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}