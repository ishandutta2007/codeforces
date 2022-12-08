#include <bits/stdc++.h>
using namespace std;
string s, res1, t, res2;
vector<int> Vec;
vector<int> solve(const string & s) {
	int n = s.size();
	vector<int> dsy[2] = {vector<int>(n+1), vector<int>(n)};
	for (int z = 0; z < 2; ++z)
		for (int i = 0, l = 0, r = 0; i < n; i++) {
			int t = r - i + !z;
			if (i < r) dsy[z][i] = min(t, dsy[z][l + t]);
			int L = i - dsy[z][i], R = i + dsy[z][i] - !z;
			while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
				dsy[z][i]++, L--, R++;
			if (R > r) l = L, r = R;
		}
	Vec.clear();
	for(int i = 0; i <= n; i++) {
		Vec.push_back(dsy[0][i] * 2);
		if(i < n) Vec.push_back(dsy[1][i] * 2 + 1);
	}
	return Vec;
}
string get_Ans(string s) {
	vector<int> k = solve(s);
	int n = (int)s.size();
	vector<int> Ans(n + 1, 0);
	for(int i = 0, x; i <= n; i++) {
		x = (i - k[i]) / 2;
		Ans[x] = max(Ans[x], i);
	}
	int B = 0, idx = 0, z = 0;
	for(int i = 0, x, y; i * 2 <= n; i++) {
		if(i > 0) {
			x = i - 1; y = n - 1 - x;
			if(s[x] != s[y]) break;
		}
		z = max(z, Ans[i]);
		if(z > B) B = z, idx = i;
	}
	return s.substr(0, idx) + s.substr(idx, z - 2 * idx) + s.substr(n - idx, idx);
}
int main() {
	int T; cin >> T; 
	while(T--) {
		cin >> s; 
		res1 = get_Ans(s), t = s;
		reverse(t.begin(), t.end());
		res2 = get_Ans(t);
		if(res1.size() < res2.size()) res1 = res2;
		cout << res1 << endl;
	}
}