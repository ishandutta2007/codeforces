/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	map<string, set<string>> m;
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
	 	cin >> s;
	 	size_t i = 7;
	 	while (i < s.size() && s[i] != '/')
	 		i++;
		m[s.substr(0, i)].insert(s.substr(i));
	}
	map<set<string>, set<string>> res;
	for (auto &p : m)
		res[p.second].insert(p.first);
	int cnt = 0;
	for (auto &p : res)
		cnt += (p.second.size() >= 2U);
	cout << cnt << "\n";
	for (auto &p : res)
		if (p.second.size() >= 2U) {
			for (auto &s : p.second)
				cout << s << " ";
			cout << "\n";
		}
}