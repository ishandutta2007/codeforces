/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
string s;

int f(int l, int r, char ch) {
	if (l == r)
		return 0;
	if (l == r - 1)
		return (s[l] != ch);
	int mid = (l + r) / 2;
	int an1 = 0, an2 = 0;
	for (int i = l; i < mid; i++) {
		an1 += (s[i] != ch);
	}
	for (int i = mid; i < r; i++) {
		an2 += (s[i] != ch);
	}
	return min(an1 + f(mid, r, ch + 1), an2 + f(l, mid, ch + 1));
}

void solve() {
	int n;
	cin >> n >> s;
	cout << f(0, n, 'a') << endl;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}