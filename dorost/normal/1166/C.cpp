/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], b[N], n;

int bs (int k) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (b[mid] > k) { 
			r = mid;      
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = abs(a[i]);
	sort(b, b + n);
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int in = bs(b[i] * 2);
		ans += (in - i - 1);
	}
	cout << ans;
}

int32_t main() {
	solve();
}