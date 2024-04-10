#include <bits/stdc++.h>
using namespace std;

string flip(const string& s) {
	string t = s;
	reverse(t.begin(), t.end());
	return t;
}

bool solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	set<string> two;
	for(int i = 0; i < n; ++i) {
		if(s[i].size() == 2) {
			if(two.count(flip(s[i])))
				return true;
		}
		two.insert(s[i].substr(0, 2));
	}

	two.clear();
	for(int i = n-1; i >= 0; --i) {
		if(s[i].size() == 2) {
			if(two.count(flip(s[i])))
				return true;
		}
		two.insert(s[i].substr(1, 2));
	}
	two.clear();
	for(int i = 0; i < n; ++i) {
		two.insert(s[i]);
		if(two.count(flip(s[i])))
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}