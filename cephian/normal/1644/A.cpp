#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ok(const string& s) {
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == tolower(s[i])) continue;
		bool ok = false;
		for(int j = 0; !ok && j < i; ++j) {
			ok |= tolower(s[i]) == s[j];
		}
		if(!ok) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if(ok(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}