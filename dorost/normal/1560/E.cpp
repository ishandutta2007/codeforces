/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
int cnt[26], o[26];

void solve() {
	string s;
	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	string k;
	for (int i = 0; i < t.size(); i++) {
		if (cnt[t[i] - 'a'] == 0) {
			o[t[i] - 'a'] = k.size();
			k += (t[i]);
		}
		cnt[t[i] - 'a']++;
	}
	reverse(k.begin(), k.end());
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	int x2 = -1;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
		int x = 0;
		for (int j = 0; j < 26; j++) {
			if (cnt[j])
				x++;
		}
		int ans = 0;
		for (int j = 0; j < 26; j++) {
			ans += (x - o[j]) * cnt[j];
		}
		if (ans == s.size()) {
			x2 = i;
		}
	}
	string lst;
	for (int i = 0; i <= x2; i++)
		lst += s[i];
	string s4 = lst;
	string s3 = lst;
	for (int i = 0; i < k.size(); i++) {
		string lst2;
		for (int j = 0; j < lst.size(); j++) {
			if (lst[j] != k[i]) {
				lst2 += lst[j];
			}
		}
		lst = lst2;
		s3 += lst2;
	}
	if (s3 == s) {
		cout << s4 << ' ' << k << '\n';
		return;
	} else {
		cout << -1 << '\n';
	}
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