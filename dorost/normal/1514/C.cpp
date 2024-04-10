/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

bool ok(int a, int b) {
	return __gcd(a, b) == 1;
}

void solve() {
	vector <int> v;
	int n, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if ((ok(n, i) && n % i) || i == 1) {
			v.push_back(i);
			ans *= i;
			ans %= n;
		}
	}
	int del = -1;
	if (ans != 1) {
		del = ans;
	}
	cout << v.size() - (del != -1) << '\n';
	bool f = (del == -1);
	for (int i = 0; i < (int)v.size(); i++) {
		if (v[i] != del)
			cout << v[i] << ' ';
		else if (del != -1) {
			f = true;
		}
	}
	assert(f);
	cout << '\n';
}

int32_t main() {
	solve();
}