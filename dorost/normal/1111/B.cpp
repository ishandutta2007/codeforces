/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], ps[N];

int32_t main() {
	int n, k, m, sum = 0;
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	ps[0] = a[0];
	for (int i = 1; i < n; i++) {
		ps[i] = ps[i - 1] + a[i];
	}
	int sum2 = min(m, k * n) + sum;
	ld mx = (ld)sum2 / (ld)n;
	for (int i = 0; i < min(m, n - 1); i++) {
		sum2 = sum - ps[i] + min(m - i - 1, k * (n - i - 1));
		mx = max(mx, (ld)sum2 / (ld)(n - i - 1));
	}
	cout << fixed << setprecision(10);
	cout << mx;
}