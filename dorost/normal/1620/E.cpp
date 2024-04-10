/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
int a[N];
pair <int, int> b[N];

void solve() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k, x, y;
		cin >> k;
		if (k == 1) {
			cin >> x;
			b[i] = {x, -1};
		} else {
			cin >> x >> y;
			b[i] = {x, y};
		}
	}
	reverse(b, b + q);
	for (int i = 0; i < N; i++)
		a[i] = i;
	vector <int> ans;
	for (int i = 0; i < q; i++) {
		if (b[i].S == -1)
			ans.push_back(a[b[i].F]);
		else
			a[b[i].F] = a[b[i].S];
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}