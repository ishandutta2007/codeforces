#include <bits/stdc++.h>
 
using namespace std;
 
int kmp(string s){
	vector<int> pi(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi[s.size() - 1];
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string ans = "";
	while (n--) {
		string s;
		cin >> s;
		int qnt = min(s.size(), ans.size());
		string curr = ans.substr(ans.size() - qnt, qnt);
		int sz = kmp(s+'#'+curr);
		ans += s.substr(sz);
	}
	cout << ans << '\n';
	return 0;
}