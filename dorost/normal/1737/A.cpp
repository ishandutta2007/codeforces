/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int cnt[26];

void solve() {
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		cnt[c - 'a']++;
	}
	for (int i = 0; i < k; i++) {
		char a = 'a';
		for (int j = 0; j < min(n / k, 26); j++) {
			if (cnt[j]) {
				a++;
				cnt[j]--;
			} else 
				break;
		}
		cout << a;
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}