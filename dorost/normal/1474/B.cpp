/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
vector <int> v;
const int N = 101234;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

void solve() {
	int d;
	cin >> d;
	int a = -1, b = -1;
	for (auto x : v) {
		if (x > d) {
			a = x;
			break;
		}
	}
	for (auto x : v) {
		if (x >= a + d) {
			b = x;
			break;
		}
	}
	cout << a * b << ' ';
}

int32_t main() {
	for (int i = 2; i <= N; i++) {
		if (is_prime(i)) 
			v.push_back(i);
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}