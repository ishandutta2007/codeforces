/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
int a[N];

int ask(int i, int j) {
	cout << "? " << i + 1 << ' ' << j + 1 << endl;
	int k;
	cin >> k;
	return k;
}

void solve() {
	int n;
	cin >> n;
	int x = ask(0, 1);
	int y = ask(0, 2);
	int z = ask(1, 2);
	int s = (x + y + z) / 2;
	a[0] = s - z;
	a[1] = s - y;
	a[2] = s - x;
	for (int i = 3; i < n; i++) {
		a[i] = ask(0, i) - a[0];
	}
	cout << "! ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}