#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

void solve() {
	int n;
	cin >> n;
	int x = 1, k;
	int lst;
	for (int i = 2; i * i <= n; i++) {
		lst = i;
		if (!is_prime(i))
			continue;
		int y = i;
		vector <int> v;
		for (int j = i; j <= n; j *= y) {
			v.push_back(j);
		}
		reverse(v.begin(), v.end());
		for (auto j : v) {
			cout << "B " << j << endl;
			cin >> k;
			cout << "A " << j << endl;
			cin >> k;
			if (k) {
				x *= y;
			}
		}
	}
	vector <int> v[112];
	int o = 0;
	for (int i = lst + 1; i <= n; i++) {
		if (!is_prime(i))
			continue;
		v[o / 100].push_back(i);
		o++;
	}
	cout << "A " << 1 << endl;
	cin >> k;
	int y = k;
	bool f = false;
	for (int i = 0; i < 102; i++) {
		vector <int> v2;
		for (int j = 0; j < v[i].size(); j++) {
			cout << "B " << v[i][j] << endl;
			cin >> k;
			v2.push_back(k);
			if (k != 2)
			    y--;
		}
		cout << "A " << 1 << endl;
		cin >> k;
		if (k != y) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << "A " << v[i][j] << endl;
				cin >> k;
				if (k) {
					x *= v[i][j];
					break;
				}
			}
			break;
		}
	}
	cout << "C " << x << endl;
}

int32_t main() {
	solve();
}