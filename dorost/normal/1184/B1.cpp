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
int a[N], pre[N], n, m;
pair <int, int> d[N];

int bs (int k) {
	int l = 0, r = m;
	while (l < r) {
		int mid = (l + r) / 2;
		if (d[mid].F > k) {    
			r = mid;      
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> d[i].F >> d[i].S;
	sort(d, d + m);
	pre[0] = 0;
	for (int i = 0; i < m; i++) {
		pre[i + 1] = pre[i] + d[i].S;
	}
	for (int i = 0; i < n; i++) {
		int in = bs(a[i]);
		cout << pre[in] << ' ';
	}
}

int32_t main() {
	solve();
}