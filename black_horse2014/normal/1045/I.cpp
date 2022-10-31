#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int len = s.length();
		int state = 0;
		for (int j = 0; j < len; j++) state ^= 1 << (s[j] - 'a');
		ans += cnt[state];
		for (int j = 0; j < 26; j++) ans += cnt[state^(1<<j)];
		cnt[state]++;
	}
	cout << ans << endl;
	return 0;
}