/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 151234;
int a[N], b[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map <int, bool> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	int x = a[0], y = b[0];
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0)
			x /= i, mp[i] = true;
	}
	if (x > 1)
		mp[x] = true;
	for (int i = 2; i * i <= y; i++) {
		while (y % i == 0)
			y /= i, mp[i] = true;
	}
	if (y > 1)
		mp[y] = true;
	for (auto [x, y] : mp) {
		bool f = true;
		for (int i = 1; i < n; i++) {
			if (a[i] % x && b[i] % x) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << x;
			return 0;
		}
	}
	cout << -1;
}