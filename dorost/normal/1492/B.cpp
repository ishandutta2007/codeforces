/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];
pair <int, int> pre[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	pre[0] = {a[0], 0};
	for (int i = 1; i < n; i++) {
		int x = pre[i - 1].S;
		if (a[i] > pre[i - 1].F)
			x = i;
		pre[i] = {max(a[i], pre[i - 1].F), x};
	}
	vector <int> v;
	int in = n - 1;
	while (in != -1) {
		int in2 = pre[in].S;
		for (int i = in2; i <= in; i++) {
			v.push_back(a[i]);
		}
		in = in2 - 1;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}