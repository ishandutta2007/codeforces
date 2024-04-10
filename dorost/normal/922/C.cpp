/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 100;

int lcm(int x, int y) {
	return (x * y / __gcd(x, y));
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	if (k > N) {
		cout << "No";
		return 0;
	}
	int x = 1;
	for (int i = 1; i <= k; i++) {
		x = lcm(x, i);
	}
	cerr << x << endl;
	cout << ((n + 1) % x == 0 ? "yEs" : "No");
}