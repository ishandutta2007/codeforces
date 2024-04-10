
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a(4);
	for (auto& i : a) cin >> i;
	string s;
	cin >> s;
	long long ans = 0;
	for (auto ch : s) ans += a[ch - 49];
	cout << ans;
	return 0;
}