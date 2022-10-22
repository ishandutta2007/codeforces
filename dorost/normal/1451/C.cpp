/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345, M = 28;
int cnta[M], cntb[M];

void solve() {
	int n, k;
	string a, b;
	cin >> n >> k >> a >> b;
	for (int i = 0; i < 26; i++)
		cnta[i] = 0, cntb[i] = 0;
	for (int i = 0; i < n; i++) {
		cnta[a[i] - 'a']++;
		cntb[b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (abs(cnta[i] - cntb[i]) % k) {
			cout << "No\n";
			return;
		}
		if (cnta[i] < cntb[i]) {
			cout << "No\n";
			return;
		}
		if (i == 25)
			continue;
		cnta[i + 1] += (cnta[i] - cntb[i]);
	}
	cout << "Yes\n";
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