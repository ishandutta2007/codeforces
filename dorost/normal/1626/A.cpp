/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 27;
int cnt[N];

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
	for (auto c : s)
		cnt[c - 'a']++;
	string t, r;
	for (int i = 0; i < N; i++) {
		if (cnt[i] == 2) {
			t += (i + 'a');
		} else if (cnt[i] == 1) {
			r += (i + 'a');
		}
	}
	cout << t << t << r << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}