#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n;

int score(const string& s) {
	map<char, int> freq;
	for(char c : s)
		++freq[c];
	
	int best = 0;
	for(auto [c, f] : freq) {
		int bs = 0;
		if(n == 1) {
			if(f == s.size()) bs = f-1;
			else bs = f+1;
		} else
			bs = min((int)s.size(), f+n);
		best = max(best, bs);
	}
	return best;
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a, b, c;
	cin >> n >> a >> b >> c;
	map<int, vector<string>> m;
	m[score(a)].push_back("Kuro");
	m[score(b)].push_back("Shiro");
	m[score(c)].push_back("Katie");

	auto win = m.rbegin()->second;
	if(size(win) > 1) cout << "Draw\n";
	else cout << win[0] << "\n";
}