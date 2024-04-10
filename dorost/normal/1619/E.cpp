/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ans[N], cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		cnt[i] = 0, ans[i] = -1;
	multiset <int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int ps = cnt[0];
	ans[0] = cnt[0];
	for (int i = 0; i < cnt[0]; i++)
		st.insert(0);
	for (int i = 1; i <= n; i++) {
		if (ps < i) {
			break;
		}
		ps += cnt[i];
		if (cnt[i - 1] == 0) {
			ans[i] = ans[i - 1] + cnt[i];
 			auto x = st.end();
			x--;
			int a2 = *x;
			st.erase(x);
			ans[i] += (i - 1) - a2;
		} else {
			ans[i] = ans[i - 1] - (cnt[i - 1]) + cnt[i];
		}
		for (int j = 0; j < cnt[i] - 1; j++)
			st.insert(i);
	}
	for (int i = 0; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}