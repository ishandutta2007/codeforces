#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, n;
string s;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s;
		if (s[0] == '0' || s[n - 1] == '0' || count(s.begin(), s.end(), '0') % 2) {
			cout << "NO\n";
			continue;
		}

		int c = 0;
		int cnt1 = count(s.begin(), s.end(), '1');
		int par = 0;
		string a, b;

		auto add = [&](string &s, int c) {
			s.push_back(c ? '(' : ')');
		};

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				add(a, par ? 0 : 1);
				add(b, par ? 1 : 0);
				par ^= 1;
			}
			if (s[i] == '1') {
				add(a, (2 * c < cnt1));
				add(b, (2 * c < cnt1));
				c++;
			}
		}

		cout << "YES\n" << a << "\n" << b << "\n";
	}
	return 0;
}