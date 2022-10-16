//  228

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, ans = LLONG_MAX;
	cin >> n >> k;
	vector<string> s(n);
	for (string &i : s) cin >> i;

	vector<int> dummy(k);
	for (int i = 0; i < k; i++)
		dummy[i] = i;

	do {
		int mx = -1, mn = LLONG_MAX;
		for (string x : s) {
			string temp;
			for (int i = 0; i < k; i++)
				temp += x[dummy[i]];

			mx = max(mx, stoll(temp));
			mn = min(mn, stoll(temp));
		}
		ans = min(ans, mx - mn);
	} while (next_permutation(dummy.begin(), dummy.end()));

	cout << ans << endl;
	return 0;
}