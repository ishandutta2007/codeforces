#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n; vector<int> a(n); for(auto &v: a) cin >> v;
	cin >> m; vector<int> b(m); for(auto &v: b) cin >> v;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	auto i = a.begin(), j = b.begin();
	int ans = 0;
	for(; i != a.end(); ++i) {
		while(j != b.end() && *j < *i - 1) ++j;
		if(j != b.end() && abs(*i - *j) <= 1) { ans++; ++j; }
	}
	cout << ans << endl;
	return 0;
}