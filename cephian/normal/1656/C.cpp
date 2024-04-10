#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool has1 = false;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] == 1)
			has1 = true;
	}
	if(!has1) {
		cout << "YES\n";
		return;
	}
	sort(a.begin(), a.end());
	for(int i = 1; i < n; ++i) {
		if(a[i-1] == a[i]-1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}