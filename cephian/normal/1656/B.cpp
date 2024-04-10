#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> all;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		all.insert(a);
	}
	for(int x : all) {
		if(all.count(x+k)) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}