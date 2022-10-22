/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int ans = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != t[i] && s[i] == t[i + 1] && s[i + 1] == t[i]) {
			ans++;
			swap(s[i], s[i + 1]);
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i])
			ans++;
	}
	cout << ans;
}