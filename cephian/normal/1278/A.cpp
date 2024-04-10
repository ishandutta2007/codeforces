#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		sort(s.begin(), s.end());
		bool ok = false;
		for(int i = 0; !ok && i+s.size() <= t.size(); ++i) {
			string ss = t.substr(i, s.size());
			sort(ss.begin(), ss.end());
			if(ss == s) {
				cout << "YES\n";
				ok = true;
			}
		}
		if(!ok)
			cout << "NO\n";
	}
}