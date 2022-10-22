/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set <int> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			st.insert(a[j] - a[i]);
		}
	}
	cout << st.size() << '\n'; 
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}