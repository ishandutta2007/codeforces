#pragma comment(linker, "/STACK:512000111")
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std; 


void solve() {
	// answer
	int answer = 0;
	// input

	int n, m; cin >> n >> m;
	vector<string> f(n);
	for (int i = 0; i < n; ++i) cin >> f[i];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (f[i][j] == 'B') {
			int k = i;
			for (k = i; k < n; ++k) if (f[k][j] != 'B') break;
			int l = k - i;
			cout << 1 + i + l / 2 << ' ' << 1 + j + l / 2 << endl;
			return;
		}
	}

	// solution
	

	// print answer
	cout << answer << endl;
}

int main() {
	int t; //cin >> t;
    t = 1;
	while (t-->0) solve();
	return 0;
}