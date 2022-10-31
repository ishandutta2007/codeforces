#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, r, b;
	cin >> n >> r >> b;
	int rem = r - (r / (b + 1)) * (b + 1);
	string s = "";
	for (int i = 0; i < b + 1; ++i) {
		if (i)
			s += "B";
		if (i < rem) {
			s += string(r / (b + 1) + 1, 'R');
		} else {
			s += string(r / (b + 1), 'R');
		}
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}