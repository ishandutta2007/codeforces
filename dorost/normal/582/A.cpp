/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 521 * 521;
int a[N];

void solve() {
	int n;
	cin >> n;
	map <int, int> mp;
	for (int i = 0; i < n * n; i++)
		cin >> a[i], mp[a[i]]++;
	if (n == 1) {
		cout << a[0];
		return;
	}
	vector <int> v, ans;
	int num = 0;
	for (auto x : mp) {
		v.push_back(x.F);
	}
	sort(v.begin(), v.end());
	ans.push_back(*v.rbegin());
	mp[ans[0]]--;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (!mp[v[i]])
			continue;
		while(mp[v[i]]) {
			for (int j = 0; j < ans.size(); j++) {
				mp[__gcd(ans[j], v[i])] -= 2;
			}
			ans.push_back(v[i]);
			mp[v[i]]--;
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}