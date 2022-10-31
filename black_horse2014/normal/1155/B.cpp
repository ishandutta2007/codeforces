#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; string s; cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n - 10; i++) {
		cnt += s[i] == '8';
	}
	if (cnt * 2 > n - 10) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}