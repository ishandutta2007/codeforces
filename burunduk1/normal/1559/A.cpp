/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, x, y;
	cin >> n >> x;
	forn(i, n - 1) cin >> y, x &= y;
	cout << x << "\n";
	// vector<int> a(n);
	// for (int &x : a) cin >> x;
	// #define f(a) *max_element(all(a))
	// int ans = f(a);
	// forn(r, n + 1)
	// 	forn(l, r) {
	// 		auto b = a;
	// 		forn(i, r - l)
	// 			b[i] = a[i] & a[r - i - 1];
	// 		ans = min(ans, f(b));
	// 	}
	// cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) 
		solve();
}