/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1005;
string s[N];
int cnt[26];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			cnt[(s[i][j]) - 'a']++;
		}
	}
	bool f = true;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % n)
			f = false;
	}
	cout << (f ? "Yes": "No") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}