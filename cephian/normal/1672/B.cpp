#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
	string s;
	cin >> s;
	if (s.back() == 'A')
		return false;
	int diff = 0;
	for (char c : s) {
		if (c == 'A')
			++diff;
		else
			--diff;
		if (diff < 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}