/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int in = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != a[n - i - 1]) {
			in = i;
			break;
		}
	}
	vector <int> v1, v2;
	if (in == -1) {
		cout << "YES\n";
		return;
	}
	int in2 = n - in - 1;
	in = a[in];
	in2 = a[in2];
	for (int i = 0; i < n; i++) {
		if (a[i] != in)
			v1.push_back(a[i]);
		if (a[i] != in2) {
			v2.push_back(a[i]);
		}
	}
	bool f = false;
	bool h = true;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v1[v1.size() - 1 - i])
			h = false;
	}
	f |= h;
	h = true;
	for (int i = 0; i < v2.size(); i++) {
		if (v2[i] != v2[v2.size() - 1 - i])
			h = false;
	}
	f |= h;
	cout << (f ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}