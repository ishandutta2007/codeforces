#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = 0;
	cin >> n;
	vector<int> a(n+1, 0);
	vector<int> diff(n);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		diff[i-1] = a[i] - a[i-1];
	}
	vector<int> ans;
	for(int l = 1; l <= n; ++l) {
		bool ok = true;
		for(int i = 0; i+l < n; ++i) {
			ok &= diff[i] == diff[i+l];
		}
		if(ok) ans.push_back(l);
	}
	cout << ans.size() << "\n";
	for(int x : ans)
		cout << x << " ";
	cout << "\n";

}