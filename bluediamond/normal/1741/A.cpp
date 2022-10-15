#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string s, t;
		cin >> s >> t;
		if (s == t) {
			cout << "=\n";
			continue;
		}
		if (s.back() < t.back()) {
			cout << ">\n";
			continue;
		} 
		if (s.back() > t.back()) {
			cout << "<\n";
			continue;
		} 
		int val = ((int) s.size() < (int) t.size()) ^ (s.back() == 'L');
		cout << ((!val) ? ("<") : (">")) << "\n";
	}
}