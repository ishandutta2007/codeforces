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
	int n, a[3]; cin >> n >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int ans = -1;
	for (int i = 0; a[0] * i <= n; ++i) {
		for (int k = 0; a[0] * i + a[1] * k <= n; ++k) {
			if ((n - a[0] * i - a[1] * k) % a[2]) continue;
			ans = max(ans, i + k + (n - a[0] * i - a[1] * k) / a[2]);
		}
	}
	cout << ans;
	return 0;
}