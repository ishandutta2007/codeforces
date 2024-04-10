#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef bitset<256> bs;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) --a[i];
	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) ++cnt[a[i]];
	if (*max_element(cnt.begin(), cnt.end()) * 2 > n + 1) {
		cout << -1 << endl;
		return true;
	}
	vector<int> deg(n);
	int edges = 0;
	for (int i = 0; i < n;) {
		int f = a[i];
		int j = i + 1;
		while (j < n && a[j] != a[j - 1]) {
			edges++;
			++j;
		}
		i = j;
		deg[f]++;
		deg[a[j - 1]]++;
	}

	int sd = 0, md = 0;
	for (int i = 0; i < deg.size(); ++i) {
		sd += deg[i];
		md = max(md, deg[i]);
	}

	if (md <= sd - md + 2)
		cout << n - 1 - edges << endl;
	else {
		cout << n - 1 - edges + (2 * md - sd - 2) / 2 << endl;
	}

	return true;
}

int main() {
	int t; cin >> t;
	while (solve())
		;
	return 0;
}