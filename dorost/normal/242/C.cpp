/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int x0, x1, y0, y1, n;
	cin >> x0 >> y0 >> x1 >> y1 >> n;
	set <pair <int, int>> st;
	for (int i = 0; i < n; i++) {
		int r, a, b;
		cin >> r >> a >> b;
		for (int j = a; j <= b; j++) {
			st.insert({r, j});
		}
	}
	queue <pair <pair <int, int>, int>> q;
	q.push(make_pair(make_pair(x0, y0), 0)); 
	st.erase(make_pair(x0, y0));
	int ans = -1;
	while (!q.empty()) {
		pair <pair <int, int>, int> p2 = ((q.front()));
		pair <int, int> p = p2.F;
		int d = (p2).S;
		if (p.F == x1 && p.S == y1) {
			ans = d;
		}
		q.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (st.count(make_pair(p.F + i, p.S + j))) {
					q.push(make_pair(make_pair(p.F + i, p.S + j), d + 1));
					st.erase(make_pair(p.F + i, p.S + j));
				}
			}
		}
	}
	cout << ans;
}