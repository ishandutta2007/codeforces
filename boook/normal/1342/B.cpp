#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0), cout.sync_with_stdio(0);
	int t;
	cin >> t;
	while (t --) {
		string s;
		cin >> s;
		int ok = 1;
		for (int i = 0; i < s.size(); ++ i) if (s[i] != s[0]) ok = 0;
		if (ok == 0) {
			for (int i = 0; i < s.size(); ++ i) cout << "01" ;
			cout << endl;
		}
		else {
			cout << s << "\n";
		}
	}
	return 0;
}