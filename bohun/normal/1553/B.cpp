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
		int n = s.length();
		int m = t.length();
		bool res = 0;
		for (int a = 0; a < n; a++) {
			int i = 0;
			while (a + i < n && i < m && s[a + i] == t[i]) {
				i++;
				int j = 0;
				while (i + j < m && a + i - 2 - j >= 0 && s[a + i - 2 - j] == t[i + j])
					j++;
				if (i + j == m)
					res = 1;
			}
		}
		cout << (res ? "YES\n" : "NO\n");
	}
	return 0;
}