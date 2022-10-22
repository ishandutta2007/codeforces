/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int cnt[26];

void solve() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	if (n % k) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	int mx = -1, nx = -1;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	bool f = true;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % k)
			f = false;
	}
	if (f) {
		cout << s << '\n';
		return;
	}
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'z') {
			cnt[s[i] - 'a']++;
			continue;
		}
		cnt[s[i] - 'a' + 1]++;
		int x = 0;
		for (int i = 0; i < 26; i++) {
			x += ((cnt[i] + k - 1) / k * k) - cnt[i];
		}
		if (x <= n - i - 1) {
			mx = i;
			nx = s[i] - 'a' + 1;
			cnt[s[i] - 'a']++;
			cnt[s[i] - 'a' + 1]--;
			continue;
		}
		cnt[s[i] - 'a' + 1]--;
		int y = -1;
		for (int j = s[i] - 'a' + 1; j < 26; j++) {
			if (cnt[j] % k) {
				y = j;
				break;
			}
		}
		if (y == -1) {
			cnt[s[i] - 'a']++;
			continue;
		}
		cnt[y]++;
		x = 0;
		for (int i = 0; i < 26; i++) {
			x += ((cnt[i] + k - 1) / k * k) - cnt[i];
		}
		if (x <= n - i - 1) {
			mx = i;
			nx = y;
			cnt[s[i] - 'a']++;
			cnt[y]--;
			continue;
		}
		cnt[y]--;
		cnt[s[i] - 'a']++;
	}
	string t;
	for (int i = 0; i < mx; i++) {
		t += s[i];
	}
	t += nx + 'a';
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < t.size(); i++) {
		cnt[t[i] - 'a']++;
	}
	string r;
	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < ((cnt[i] + k - 1) / k * k) - cnt[i]; j++) {
			r += i + 'a';
		}
	}
	while (r.size() + t.size() != s.size()) {
		r += 'a';
	}
	reverse(r.begin(), r.end());
	cout << t << r << '\n';
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