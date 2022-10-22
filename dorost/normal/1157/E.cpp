/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	set <int> st;
	map <int, int> mp;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		st.insert(b[i]);
		mp[b[i]]++;
	}
	for (int i = 0; i < n; i++) {
		auto in = st.lower_bound(n - a[i]);
		if (in == st.end()) {
			in = st.begin();
		}
		int x = *in;
		cout << (x + a[i]) % n << ' ';
		mp[x]--;
		if (mp[x] == 0) {
			st.erase(x);
		}
	}
}