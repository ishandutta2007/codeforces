//https://codeforces.com/problemset/problem/1203/D2
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	vector<int> rg(t.size());
	
	for (int i = int(t.size()) - 1; i >= 0; --i) {
		int pos = int(s.size()) - 1;
		if (i + 1 < int(t.size())) pos = rg[i + 1] - 1;
		while (s[pos] != t[i]) --pos;
		rg[i] = pos;
	}
	
	int ans = 0;
	int pos = 0;
	for (int i = 0; i < int(s.size()); ++i) {
		int rpos = int(s.size()) - 1;
		if (pos < int(t.size())) rpos = rg[pos] - 1;
		ans = max(ans, rpos - i + 1);
		if (pos < int(t.size()) && t[pos] == s[i]) ++pos;
	}
	
	cout << ans << endl;
	
	return 0;
}