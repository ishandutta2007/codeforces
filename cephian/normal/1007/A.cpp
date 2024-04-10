#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	sort(a.begin(), a.end());
	int j = 1, ans = 0;
	for(int i = 0; i < n; ++i) {
		while(j < n && a[j] <= a[i]) ++j;
		if(j == n) break;
		++ans, ++j;
	}
	cout << ans << "\n";
}