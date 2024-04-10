/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 26;
int cnt[N];

void solve() {
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (auto c : s) {
		cnt[c - 'a']++;
	}
	if (t == "abc" && cnt[0] && cnt[1] && cnt[2]) {
		int i = 0;
		for (int j = 0; j < cnt[i]; j++) {
			cout << char(i + 'a');
		}
		i = 2;
		for (int j = 0; j < cnt[i]; j++) {
			cout << char(i + 'a');
		}
		i = 1;
		for (int j = 0; j < cnt[i]; j++) {
			cout << char(i + 'a');
		}
		for (int i = 3; i < 26; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << char(i + 'a');
			}
		}
	} else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << char(i + 'a');
			}
		}
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}