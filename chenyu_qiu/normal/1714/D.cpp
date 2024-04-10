#include <bits/stdc++.h>
using namespace std;
#define ll long long
#ifndef Cishoon
#	define dlog
#	define freopen
#endif
 
int match(string& t, string& s, int pos)
{
	for (char ch : s) {
		if (ch == t[pos++])
			continue;
		else {
			return -1;
		}
	}
	return pos;
}
 
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string t;
		cin >> t;
		int n;
		cin >> n;
 
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
 
		// find the first match
		int p = 0;
		vector<pair<int, int>> ans(105, {0, 0});
		int cnt = 0;
 
		for (int k = 1; k; k++) {
			int begin_p = p;
 
			for (int i = 0; i < n; i++) {
				for (int j = 0; begin_p - j >= 0; j++) {
					int tmp = match(t, s[i], begin_p - j);
					if (tmp > p) {
						p = tmp;
						ans[k-1] = {i + 1, begin_p - j + 1};
						cnt = k;
					}
				}
			}
 
			if (p == t.size()) {
				cout << cnt << '\n';
				for (int i = 0; i < cnt; i++) {
					cout << ans[i].first << ' ' << ans[i].second << '\n';
				}
				goto nxt;
			}
 
			if (p == begin_p) {
				cout << -1 << '\n';
				goto nxt;
			}
		}
 
 
 
	nxt:
		cnt = 0;
	}
 
 
	return 0;
}