/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012, M = 998244353;
#define int long long
int n, k;
string s;

int tav(int x, int n) {
	if (n == 0)
		return 1;
	int ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}
 
int fac(int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++) {
		ans *= i;
		ans %= M;
	}
	return ans;
}
 
int C(int k, int n) {
	return (fac(n) * (inv((fac(n - k) * fac(k)) % M)) % M) % M;
}
 
int h(int l, int r) {
	if (r < l)
		return 1;
	int x = 0, y = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] == '1')
			x++;
		else
			y++;
	}
	return C(x, x + y);
}

inline void solve() {
	cin >> n >> k >> s;
	if (k == 0) {
		cout << 1;
		return;
	}
	vector <int> v;
	vector <pair <int, int>> w;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			v.push_back(i);
	}
	v.push_back(n);
	if (v.size() <= k) {
		cout << 1;
		return;
	}
	w.push_back({0, v[k] - 1});
	for (int i = 0; i < (int)v.size() - k - 1; i++) {
		w.push_back({v[i] + 1, v[k + i + 1] - 1});
	}
	int ans = h(w[0].F, w[0].S);
	for (int i = 1; i < (int)w.size(); i++) {
		int l = w[i].F, r = w[i].S;
		int l2 = w[i - 1].F, r2 = w[i - 1].S;
		if (r2 < l) {
			ans += h(l, r) - 1;
			ans %= M;
			continue;
		}
		int a = h(l, r);
		a -= h(l, r2);
		if (a < 0)
			a += M;
		a %= M;
		ans += a;
		ans %= M;
	}
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	while (t--) {
		solve();
	}
}