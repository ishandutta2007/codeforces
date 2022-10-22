/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 300001;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int in = 0;
	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		while (a[in] == in + 1) {
			in++;
		}
		if (in >= n) {
			break;
		}
		int x = in, y = a[in] - 1;
		if (abs(x - y) >= n / 2) {
			v.push_back({x + 1, y + 1});
			swap(a[x], a[y]);
		} else {
			v.push_back({x + 1, (x < n / 2 ? n - 1 : 0) + 1});
			swap(a[x], a[(x < n / 2 ? n - 1 : 0)]);
			if (abs(y - (x < n / 2 ? n - 1 : 0)) >= n / 2) {
				v.push_back({(x < n / 2 ? n - 1 : 0) + 1, y + 1});
				swap(a[y], a[(x < n / 2 ? n - 1 : 0)]);
				v.push_back({x + 1, (x < n / 2 ? n - 1 : 0) + 1});
				swap(a[x], a[(x < n / 2 ? n - 1 : 0)]);
			} else {
				v.push_back({(x < n / 2 ? n - 1 : 0) + 1, (x >= n / 2 ? n - 1 : 0) + 1});
				swap(a[(x < n / 2 ? n - 1 : 0)], a[(x >= n / 2 ? n - 1 : 0)]);
				v.push_back({(x >= n / 2 ? n - 1 : 0) + 1, y + 1});
				swap(a[(x >= n / 2 ? n - 1 : 0)], a[y]);
				v.push_back({(x < n / 2 ? n - 1 : 0) + 1, (x >= n / 2 ? n - 1 : 0) + 1});
				swap(a[(x < n / 2 ? n - 1 : 0)], a[(x >= n / 2 ? n - 1 : 0)]);
				v.push_back({x + 1, (x < n / 2 ? n - 1 : 0) + 1});
				swap(a[x], a[(x < n / 2 ? n - 1 : 0)]);
			}
		}
	}
	cout << v.size() << ' ';
	for (auto [x, y] : v) {
		cout << x << ' ' << y << ' ';
	}
}