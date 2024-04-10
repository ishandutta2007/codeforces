#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;	
	cin >> s;
	for(int t = s.size(); t >= 0; --t) {
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] != s[s.size()-1-i])
				goto skp;
		}
		cout << "YES\n";
		return 0;
		skp:;
		s = "0" + s;
	}
	cout << "NO\n";
}