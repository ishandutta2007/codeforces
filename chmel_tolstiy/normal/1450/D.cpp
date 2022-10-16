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
	vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) --a[i];
	vector<int> cnt(n); for (int i = 0; i < n; ++i) ++cnt[a[i]];
	string result(n, '0');
	if (*max_element(cnt.begin(), cnt.end()) == 1) result[0] = '1';

	int l = 0, r = n - 1;
	int len = 0;
	while (l <= r) {
		if (cnt[len] == 0) break;
		if (cnt[len] > 1) {
			++len;
			break;
		}
		if (a[l] == len || a[r] == len) {
			if (a[l] == len) ++l; else --r;
			++len;
		}
		else {
			++len;
			break;
		}
	}

	cerr << len << endl;
	for (int i = n - len; i < n; ++i) result[i] = '1';
	cout << result << endl;

	return true;
}

int main() {
	int t; cin >> t;
	while (solve())
		;
	return 0;
}