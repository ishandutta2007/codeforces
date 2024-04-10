/* 	* In the name of GOD 
 * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
int n;
const int N = 101234;
int pre[N], m[N];
pair <int, int> a[N];

int bs (int x) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (m[mid] >= x) {    
			r = mid;      
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

int sum(int l, int r) {
	return pre[r] - (l == 0 ? 0 : pre[l - 1]);
}

void solve() {
	int d;
	cin >> n >> d;
	pre[0] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;
	sort(a, a + n);
	pre[0] = a[0].S;
	m[0] = a[0].F;
	for (int i = 1; i < n; i++) 
		pre[i] = pre[i - 1] + a[i].S, m[i] = a[i].F;
	pre[n] = pre[n - 1];
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, sum(i, bs(m[i] + d) - 1));
	}
	cout << mx;
}

int32_t main() {
	int t = 1;
	//	cin >> t;
	while (t--) {
		solve();
	}
}