#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	set<char> tot;
	for(char c : s)
		tot.insert(c);
	const int period = tot.size();
	for (int i = period; i < s.size(); ++i) {
		if(s[i] != s[i-period]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}