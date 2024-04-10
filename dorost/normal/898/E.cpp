/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

int32_t main() {
	int n;
	cin >> n;
	int num = 0, n2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int x = sqrt(a[i]);
		if (x * x == a[i]) {
			num++;
		}
		if (a[i] == 0) {
			n2++;
		}
	}
	if (num >= n / 2) {
		int x = num - n / 2;
		int ans = num - n / 2;
		ans += max(0LL, x - (num - n2));
		cout << ans;
		return 0;
	}
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int x = floor(sqrt(a[i]));
		int y = ceil(sqrt(a[i]));
		int mn = min(a[i] - x * x, y * y - a[i]);
		if (mn == 0)
			continue;
		v.push_back(mn);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n / 2 - num; i++) {
		ans += v[i];
	}
	cout << ans;
}