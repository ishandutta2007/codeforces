/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	k--;
	int x = k / (ll)n, y = k % (ll)n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int num = 0;
	bool f = false;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[x]) {
			if (!f) {
				f = true;
				x = i;
			}
			num++;
		}
	}
	cout << a[x] << ' ' << a[(k - x * n) / num];
}