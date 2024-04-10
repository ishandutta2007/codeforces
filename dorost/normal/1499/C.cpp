/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int n, pa[N], pb[N], mna[N], mnb[N];

int ans(vector <int> v, bool w) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		if (w) {
			pb[i] = (n - i - 1) * mnb[i * 2 + 1] + sum;
		} else {
			pa[i] = (n - i - 1) * mna[i * 2] + sum;
		}
	}
}

void solve() {
	cin >> n;
	vector <int> a, b;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i % 2 == 0) {
			if (i == 0) 
				mna[i] = x;
			else
				mna[i] = min(mna[i - 2], x);
			a.push_back(x);
		} else {
			if (i == 1) 
				mnb[i] = x;
			else
				mnb[i] = min(mnb[i - 2], x);
			b.push_back(x);
		}
	}
	ans(a, 0), ans(b, 1);
	int mn = LLONG_MAX;
	for (int i = 0; i < n / 2; i++) {
		mn = min(mn, pa[i] + pb[i]);
	}
	for (int i = 0; i < n / 2 - (n % 2 == 0); i++) {
		mn = min(mn, pa[i + 1] + pb[i]);
	}
	cout << mn << '\n';
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