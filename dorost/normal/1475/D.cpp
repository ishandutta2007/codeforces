/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], pre1[N], pre2[N];

void solve() {
	int n, m;
	cin >> n >> m;
	vector <int> a1, a2;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			a1.push_back(a[i]);
		else
			a2.push_back(a[i]);
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	reverse(a1.begin(), a1.end());
	reverse(a2.begin(), a2.end());
	pre1[0] = 0;
	pre2[0] = 0;
	for (int i = 0; i < a1.size(); i++) {
		pre1[i + 1] = (pre1[i] + a1[i]);
	}
	for (int i = 0; i < a2.size(); i++) {
		pre2[i + 1] = (pre2[i] + a2[i]);
	}
	int mn =  a1.size() + a2.size() * 2 + 1;
	for (int i = 0; i <= a1.size(); i++) {
		int s = m - pre1[i];
		int in = lower_bound(pre2, pre2 + a2.size() + 1, s) - pre2;
		if (in == a2.size() + 1)
			continue;
		mn = min(mn, in * 2 + i);
	}
	cout << (mn > a1.size() + a2.size() * 2 ? -1 : mn) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}