/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int ans[N];

int32_t main() {
	int n, m;
	set <int> st, st2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		st.insert(i), st2.insert(i);
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		auto aa = st.lower_bound(l);
		auto bb = st.upper_bound(r);
		vector <int> v;
		while (aa != bb) {
			if (*aa == x) {
				aa++;
				continue;
			}
			st2.erase(*aa);
			v.push_back(*aa);
			ans[*aa - 1] = x;
			aa++;
		}
		for (auto aaa : v)
			st.erase(aaa);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}