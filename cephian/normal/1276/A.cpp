#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		set<int> ans;
		for(int i = 0; i+2 < s.size(); ++i) {
			if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
				if(i > 0 && s[i-1] == 'o')
					ans.insert(i+1);
				else
					ans.insert(i);
			}
			else if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
				if(i+3 < s.size() && s[i+3] == 'o')
					ans.insert(i+1);
				else
					ans.insert(i+2);
			}
		}
		cout << ans.size() << '\n';
		for(int x : ans) cout << x+1 << ' ';
		cout << '\n';
	}
}