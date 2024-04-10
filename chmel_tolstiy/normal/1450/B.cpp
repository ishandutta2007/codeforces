#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

bool solve() {
	int n, k;
	if (!(cin >> n >> k)) return false;
	vi x(n), y(n);
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i) {
		bool ok = true;
		for (int j = 0; j < n; ++j) if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) ok = false;
		if (ok) {
			cout << 1 << endl;
			return true;
		}
	}
	cout << -1 << endl;
	return true;
}

int main() {
	int t; cin >> t;
	while (solve())
		;
	return 0;
}