#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		string t = s;
		sort(t.begin(), t.end());
		int res = 0;
		for (int i = 0; i < n; i++)
			res += s[i] != t[i];
		cout << res << endl;
	}
	return 0;
}