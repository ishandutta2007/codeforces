/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 103;
int ans[N];

void solve() {
	int n;
	cin >> n;
	set <int> st;
	int anss = 0;
	for (int i = 0; i < n; i++) {
		char ch;
		int x;
		cin >> ch >> x;
		if (ch == '+')
			st.insert(x);
		else {
			if (!st.count(x)) {
				anss++;
				for (int j = 0; j < i; j++) {
					ans[j]++;
				}
			}
			st.erase(x);
		}
		ans[i] = st.size();
	}
	cout << max(anss, *max_element(ans, ans + n));
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}