#include <bits/stdc++.h>
using namespace std;

bool ok(string s) {
	int i = 0, j = s.length() / 2;
	while(j < s.length()) {
		if(s[i] == '*' || s[j] == '*') ;
		else if(s[i] != s[j]) return false;
		i++, j++;
	}
	return true;
}

int main() {
	string s; int k; cin >> s >> k;
	while(k--) s = s + '*';
	int ans = 0;
	for(int i = 0; i < s.length(); ++i)
		for(int j = i + 1; j < s.length(); j += 2) {
			string sub = s.substr(i, j - i + 1);
			if(ok(sub)) ans = max(ans, (int)sub.length());
		}
	cout << ans << endl;
	return 0;
}