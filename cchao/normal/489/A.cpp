#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i]; b[i] = a[i];
	}
	sort(b.begin(), b.end());
	vector<pair<int,int>> ans;
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[i]) continue;
		int t = i;
		for(int j = i + 1; j < n; ++j) {
			if(a[j] != b[i]) continue;
			if(a[i] == b[j]) { t = j; break; }
			t = j;
		}
		swap(a[i], a[t]);
		ans.push_back({i,t});
	}
	cout << ans.size() << endl;
	for(auto v: ans) cout << v.first << ' ' << v.second << endl;
	return 0;
}