#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		reverse(t.begin(), t.end());
		int m = t.length();
		int i = s.length() - 1;
		int j = 0;
		while (i >= 0 && j < m) {
			while (i >= 0 && s[i] != t[j])
				i -= 2;
			if (i >= 0) {
				i--;
				j++;
			}
		}
		cout << (j == m ? "YES\n" : "NO\n");
	}
	return 0;
}