/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
set <int> st;

void ans(vector <int> a) {
	if (a.empty())
		return;
	int x = a[0], y = a[a.size() - 1];
	int an = (x + y) / 2;
	vector <int> a1, a2;
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] <= an)
			a1.push_back(a[i]);
		else
			a2.push_back(a[i]);
		sum += a[i];
	}
	st.insert(sum);
	if (a1.size() == 0 || a2.size() == 0)
		return;
	ans(a1);
	ans(a2);
}

void solve() {
	st.clear();
	int n, q;
	cin >> n >> q;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ans(a);
	for (int i = 0; i < q; i++) {
		int s;
		cin >> s;
		cout << (st.count(s) ? "Yes" : "No") << '\n';
	}
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