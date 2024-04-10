/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
int n;

bool ok(int x) {
	return (x >= 1 && x <= n);
}

void solve() {
	int k, s;
	cin >> n >> k >> s;
	if (s > (n - 1) * k || s < k) {
		cout << "NO";
		return;
	}
	cout << "YES\n";
	int a = s / k, b = s % k, lst = 1;
	for (int i = 0; i < k; i++) {
		int d = a + (i < b);
		if (ok(lst - d)) {
			lst -= d;
		}else{
			lst += d;
		}
		cout << lst << ' ';
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}