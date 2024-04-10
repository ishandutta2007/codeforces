/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int aa[N], ba[N], cnta[N], cntb[N];

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = 0; i <= a; i++)
		cnta[i] = 0;
	for (int i = 0; i <= b; i++)
		cntb[i] = 0;
	int ans = (k * (k - 1)) / 2;
	for (int i = 0; i < k; i++)
		cin >> aa[i], cnta[aa[i]]++;
	for (int i = 0; i < k; i++)
		cin >> ba[i], cntb[ba[i]]++;
	for (int i = 0; i <= a; i++) {
		ans -= cnta[i] * (cnta[i] - 1) / 2;
	}
	for (int i = 0; i <= b; i++) {
		ans -= cntb[i] * (cntb[i] - 1) / 2;
	}
	cout << ans << ' ';
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