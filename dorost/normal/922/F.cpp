/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int cnt[N], ps2[N];
vector <int> p;

vector <int> solve (int n, int k, int x) {
	int ans = 0;
	vector <int> v;
	v.push_back(1);
	int l = upper_bound(p.begin(), p.end(), n / 2) - p.begin(), r = upper_bound(p.begin(), p.end(), n) - p.begin() - 1;
	int c = r - l + 1;
	if (ans + c >= k) {
		for (int i = l; i < l + k - ans; i++) {
			v.push_back(p[i]);
		}
		return v;
	}
	for (int i = 2; i <= n; i++) {
		if (cnt[i] == 1 && i > n / 2 || i == x)
			continue;
		ans += cnt[i] - (i % x == 0 && x != 1);
		v.push_back(i);
		if (ans + c >= k) {
			if (k - ans < 0) {
				return {};
			}
			for (int i = l; i < l + k - ans; i++) {
				v.push_back(p[i]);
			}
			return v;
		}
	}
	return {};
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cnt[1] = 0;
	for (int i = 1; i < N; i++) {
		if (cnt[i] == 1) 
			p.push_back(i);
		for (int j = i * 2; j < N; j += i) {
			cnt[j]++;
		}
		ps2[i] = ps2[i - 1] + cnt[i];
	}
	int n, k;
	cin >> n >> k;
	if (k > ps2[n]) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		vector <int> ans;
		for (int x = 1; x <= 11; x++) {
			if (solve(n, k, x).size() > 0)
				ans = solve(n, k, x);
		}
		cout << ans.size() << '\n';
		for (auto x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}