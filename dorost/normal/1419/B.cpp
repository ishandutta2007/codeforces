/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
vector <int> v;
const int Inf = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000ll;

void solve() {
	int x;
	cin >> x;
	int sum = 0;
	int i = 0;
	while (sum <= x) {
		sum += v[i];
		if (sum > x)
			break;
		i++;
	}
	cout << i << ' ';
}

int32_t main() {
	int x = 1;
	while (((x - 1) * (x)) / 2 < Inf) {
		x *= 2;
		v.push_back(((x - 1) * (x)) / 2);
//		cout << v[v.size() - 1] << ' ';
	}
//	cout << endl;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}