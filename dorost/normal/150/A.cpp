/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	int n;
	cin >> n;
	if (is_prime(n) || n == 1) {
		cout << 1 << ' ' << 0 << '\n';
		return 0;
	}
	vector <int> v;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			v.push_back(i);
		}
	}
	if (n != 1) {
		v.push_back(n);
	}
	if (v.size() == 2) {
		cout << 2;
		return 0;
	} else {
		cout << "1 " << v[0] * v[1];
	}
}