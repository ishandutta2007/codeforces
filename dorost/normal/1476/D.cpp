/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int pre[N], suf[N];

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		int x = i;
		if (s[i] == 'L') {
			pre[i] = 0;
			continue;
		}
		i++;
		while (i < n && s[i] == ((i - x) % 2 == 0 ? 'R' : 'L')) {
			i++;
		}
		for (int j = x; j <= i; j++) {
			pre[j] = (s[j] == 'L' ? 0 : i - j);
		}
		i--;
	}
	for (int i = n - 1; i >= 0; i--) {
		int x = i;
		if (s[i] == 'R') {
			suf[i] = 0;
			continue;
		}
		i--;
		while (i >= 0 && s[i] == ((x - i) % 2 == 0 ? 'L' : 'R')) {
			i--;
		}
		for (int j = x; j >= i; j--) {
			suf[j] = (s[j] == 'R' ? 0 : j - i);
		}
		i++;
	}
	/*for (int i = 0; i < n; i++) {
		cout << pre[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << suf[i] << ' ';
	}
	cout << '\n';*/
	cout << pre[0] + 1 << ' ';
	for (int i = 1; i < n; i++) {
		cout << pre[i] + suf[i - 1] + 1 << ' ';
	}
	cout << suf[n - 1] + 1;
	cout << '\n';
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