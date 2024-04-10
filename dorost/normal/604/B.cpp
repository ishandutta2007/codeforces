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
int s[N], n, k;

bool check(int x) {
	int fst = 0, lst = (n) - 1, cnt = 0;
	while (fst <= lst) {
		if (s[fst] + s[lst] <= x) {
			fst++;
			lst--;
		} else {
			lst--;
		}
		cnt++;
		if (cnt > k)
			return false;
	}
	return true;
}

int bs () {
	int l = s[n - 1], r = 101234567890000ll;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {    
			r = mid;      
		} else {
			l = mid + 1;  
		}
	}
	assert(check(l));
	return l;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	cout << bs();
}

int32_t main() {
	solve();
}