/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
int a[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	int n;
	cin >> n;
	if (n == 1 || is_prime(n)) {
		cout << n << ' ' << 0;
		return 0;
	}
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			a[i]++;
		}
	}
	if (n != 1) {
		a[n]++;
	}
	int x = 1, mx = 0, cnt = 0;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		mx = max(mx, a[i]);
		if (a[i]) {
			v.push_back(a[i]);
			x *= i;
		}
	}
	sort(v.begin(), v.end());
	if (v[0] == v.back()) {
		if (1 << (int)log2(mx) == mx) {
			cout << x << ' ' << (int) log2(mx);
			return 0;
		}
	}
	cnt = 1;
	while (mx != 1) {
		mx = mx + 1;
		mx /= 2;
		cnt++;
	}
	cout << x << ' ' << cnt;
}