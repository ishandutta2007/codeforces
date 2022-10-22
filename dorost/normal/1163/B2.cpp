/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], cnt[N], lst[N];

void solve() {
	set <pair <int, int>> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		lst[i] = -1;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		st.erase({cnt[a[i]], lst[a[i]]});
		cnt[a[i]]++;
		st.insert({cnt[a[i]], i});
		if (st.size() == 1)
			mx = max(mx, i + 1);
		if ((*st.rbegin()).F - (*st.begin()).F == 1) {
			pair <int, int> x = *st.rbegin();
			st.erase(x);
			if (st.size() == 0 || (*st.rbegin()).F == (*st.begin()).F) {
				mx = max(mx, i + 1);
			}
			st.insert(x);
		}
		if ((*st.begin()).F == 1) {
			pair <int, int> x = *st.begin();
			st.erase(x);
			if (st.size() == 0 || (*st.rbegin()).F == (*st.begin()).F) {
				mx = max(mx, i + 1);
			}
			st.insert(x);
		}
		lst[a[i]] = i;
	}
	cout << mx << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}