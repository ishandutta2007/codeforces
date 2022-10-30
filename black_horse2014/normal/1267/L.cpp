#include <bits/stdc++.h>

#ifdef LOCAL
#include "E:\\Competitive-Programming\\Template\\Standard Template Codes\\debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, l, k; cin >> n >> l >> k; k--;
	string s; cin >> s;
	sort(s.begin(), s.end());
	vector<string> ret(n);
	int pre = 0, cur = 0;
	for (int i = 0; i < l; i++) {
		int newp = pre;
		for (int j = pre; j <= k; j++) {
			if(j > pre && s[cur] != s[cur - 1]) {
				newp = j;
			}
			ret[j] += s[cur++];
		}
		pre = newp;
	}
	for (int i = 0; i < n; i++) {
		while(ret[i].size() < l) {
			ret[i] += s[cur++];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ret[i] << '\n';
	}
	return 0;
}