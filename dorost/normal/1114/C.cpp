/* 	* In the name of GOD  */

#include "bits/stdc++.h"

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, b;
	cin >> n >> b;
	vector <pair <int, int>> v;
	if (is_prime(b))
		v.push_back({b, 1});
	int b2 = b;
	int x = b;
	for (int i = 2; i * i <= b2; i++) {
		if (b % i == 0) {
			int a = 0;
			while (b % i == 0) {
				b /= i;
				a++;
				x /= i;
			}
			v.push_back({i, a});
		}
	}
	if (x != 1) 
		v.push_back({x, 1});
	int mn = LLONG_MAX;
	for (auto [x, y] : v) {
		int ans = 0;
		int n2 = n;
		while (n2) {
			n2 /= x;
			ans += n2;
		}
		mn = min(mn, ans / y);
	}
	cout << mn;
}