/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int prea[N], preb[N], n, k;

bool check(int l, int r) {
	if (prea[r] - (l ? prea[l - 1] : 0) <= k || preb[r] - (l ? preb[l - 1] : 0) <= k)
		return true;
	return false;
}

int bs (int k) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (!check(k, mid)) { 
			r = mid;
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

int32_t main() {
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		prea[i] = (i ? prea[i - 1] : 0) + (s[i] == 'a');
		preb[i] = (i ? preb[i - 1] : 0) + (s[i] == 'b');
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x = bs(i);
		mx = max(mx, x - i);
	}
	cout << mx;
}