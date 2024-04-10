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
	int n;
	if (!(cin >> n)) return false;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vi cnt(3);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (s[i][j] == 'X') {
		++cnt[(i + j) % 3];
	}
	int dg = min_element(cnt.begin(), cnt.end()) - cnt.begin();
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (s[i][j] == 'X' && (i + j) % 3 == dg) {
		s[i][j] = 'O';
	}
	for (int i = 0; i < n; ++i)
		cout << s[i] << endl;
	return true;
}

int main() {
	int t; cin >> t;
	while (solve())
		;
	return 0;
}