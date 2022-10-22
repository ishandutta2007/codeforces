/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], b[N];
pair <int, int> c[N];

int32_t main() {
	int n, r, avg;
	cin >> n >> r >> avg;
	avg = avg * n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		avg -= a[i];
		c[i] = {b[i], a[i]};
	}
	if (avg <= 0) {
		cout << 0;
		return 0;
	}
	int ans = 0;
	sort(c, c + n);
	for (int i = 0; i < n; i++) {
		int rem = r - c[i].S;
		if (avg <= rem) {
			ans += c[i].F * avg;
			break;
		} else {
			ans += c[i].F * rem;
			avg -= rem;
		}
	}
	cout << ans;
}