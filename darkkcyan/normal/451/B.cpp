#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	static vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	int l, r;
	for (l  = 0; l < n - 1; ++l) if (a[l] > a[l + 1]) break;
	
	if (l == n - 1) return cout << "yes\n1 1", 0;
	for (r = n - 1; r > 0; --r) if (a[r] < a[r - 1]) break;
	
	reverse(a.begin() + l, a.begin() + r + 1);
	// cout << l << ' ' << r << endl;
	for (int i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) return cout << "no", 0;
	cout << "yes\n" << (l + 1) << ' ' << (r + 1);
	
	return 0;
}