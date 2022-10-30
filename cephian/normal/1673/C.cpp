#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e4 + 5;
const int mod = 1e9 + 7;

ll ways[N] = {};

void solve() {
	int n;
	cin >> n;
	cout << ways[n] << '\n';
}

bool ispal(int x) {
	vector<int> c;
	while (x) {
		c.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < c.size() - 1 - i; ++i) {
		if (c[i] != c[c.size() - 1 - i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ways[0] = 1;
	for (int i = 1; i < N; ++i) {
		if (!ispal(i))
			continue;
		for (int j = i; j < N; ++j) {
			ways[j] += ways[j - i];
			if (ways[j] > mod)
				ways[j] -= mod;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}