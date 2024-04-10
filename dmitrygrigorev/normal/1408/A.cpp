#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	for (auto &x : c) cin >> x;

	vector<int> ans(n);
	ans[0] = a[0];

	for (int i = 1; i < n-1; ++i) {
		if (a[i] != ans[i-1]) ans[i] = a[i];
		if (b[i] != ans[i-1]) ans[i] = b[i];
		if (c[i] != ans[i-1]) ans[i] = c[i];
	}

	int i = n-1;

	if (a[i] != ans[0] && a[i] != ans[n-2]) ans[n-1] = a[i];
	if (b[i] != ans[0] && b[i] != ans[n-2]) ans[n-1] = b[i];
	if (c[i] != ans[0] && c[i] != ans[n-2]) ans[n-1] = c[i];

	for (auto x : ans) cout << x << " ";
	cout << '\n';

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i <t ; ++i) solve();

}