#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ve vector
#define ii pair<int, int>
#define ll pair<long, long>
#define sz(v) ((int) (v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define xx first
#define yy second
#define pb push_back

int main() {
	int n; cin >> n;
	ve<ii> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i].xx, a[i].yy = i;
	sort(a.rbegin(), a.rend());
	ve<int> ans(n);
	ans[a[0].yy] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i].xx == a[i - 1].xx) ans[a[i].yy] = ans[a[i - 1].yy];
		else ans[a[i].yy] = i + 1;
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
	return 0;
}