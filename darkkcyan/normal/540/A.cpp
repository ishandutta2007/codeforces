#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> ws >> s >> ws;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		char ch; cin >> ch;
		int t = abs(ch - s[i]);
		ans += min(t, 10 - t);
	}
	cout << ans;
	return 0;
}