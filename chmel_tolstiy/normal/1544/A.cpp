#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;
	cout << *max_element(s.begin(), s.end()) << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while (t --> 0)
		solve();
	return 0;
}