#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		string s, t, p;
		cin >> s >> t >> p;

		vector<char> missing;
		int k = 0;
		for(char c : t) {
			if(k < (int)s.size() && s[k] == c) {
				++k;
			} else
				missing.push_back(c);
		}
		if(k != (int)s.size()) {
			cout << "NO\n";
			continue;
		}
		sort(missing.begin(), missing.end());
		sort(p.begin(), p.end());

		k = 0;
		for(char c : p) {
			if(k < (int)missing.size() && missing[k] == c) {
				++k;
			} else {
		
			}
		}
		if(k != (int)missing.size()) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
}