/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int cntx[N], cnty[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	set <int> sa, st;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n + 1; i++) 
		sa.insert(i), st.insert(i);
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			cntx[x]++;
			cnty[y]++;
			sa.erase(x);
			st.erase(y);
		} else if (t == 2) {
			cntx[x]--;
			cnty[y]--;
			if (cntx[x] == 0)
				sa.insert(x);
			if (cnty[y] == 0)
				st.insert(y);
		} else {
			int x2, y2;
			cin >> x2 >> y2;
			bool ans = false;
			auto in = sa.lower_bound(x);
			if (in != sa.end() && *in > x2)
				ans = true;
			auto in2 = st.lower_bound(y);
			if (in2 != st.end() && *in2 > y2)
				ans = true;
			cout << (ans ? "YES" : "NO") << '\n';
		}
	}
}