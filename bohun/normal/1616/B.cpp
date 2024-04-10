#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		string t = string(1, s[0]);
		int j = 1;
		while (j < n && s[j - 1] >= s[j]) {
			t += s[j++];
		}

		for (int i = j - 1; 0 <= i; i--)
			t.push_back(t[i]);

		cout << min(t, string(2, s[0])) << '\n';
	}
	return 0;
}