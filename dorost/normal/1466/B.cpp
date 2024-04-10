/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n + 10; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i < 2 * n + 5; i++) {
		if ((cnt[i + 1] == 0 && cnt[i] > 0) || cnt[i] > 1) {
			cnt[i]--;
			cnt[i + 1]++;
		}
	}
	int x = 0;
	for (int i = 0; i < 2 * n + 6; i++) {
		if (cnt[i])
			x++;
	}
	cout << x << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}