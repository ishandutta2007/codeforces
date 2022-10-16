#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int w, h; cin >> h >> w;

	for (int i = 0; i < w; ++i)
		cout << 1 - i % 2;
	cout << endl;
	for (int v = 1; v < h - 2; ++v) {
		cout << 1 - v % 2;
		for (int i = 1; i < w - 1; ++i) cout << 0;
		cout << 1 - v % 2;
		cout << endl;
	}
	for (int i = 0; i < w; ++i)
		cout << 0;
	cout << endl;
	for (int i = 0; i < w; ++i)
		cout << 1 - i % 2;
	cout << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while (t-- > 0)
		solve();
	return 0;
}