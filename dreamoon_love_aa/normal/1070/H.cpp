#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
map<string, int> f;
map<string, string> g;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		set<string> a;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; i + j <= s.size(); j++) {
				a.insert(s.substr(i, j));
			}
		}
		for (string i: a) {
			f[i]++;
			g[i] = s;
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		if (f.find(s) != f.end()) {
			cout << f[s] << ' ' << g[s] << endl;
		} else {
			cout << 0 << ' ' << '-' << endl;
		}
	}
	return 0;
}