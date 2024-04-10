#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

char other(char c) {
	return c == 'R' ? 'B' : 'R';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int p = 0;
		while (p < n && s[p] == '?')
			p++;
		char a = (p < n ? s[p] : 'R');
		auto t = s;
		rep(i, 0, p)
			t[i] = (i % 2 == p % 2 ? a : other(a));
		rep(i, p, n) {
			t[i] = (s[i] != '?' ? s[i] : other(a));
			a = t[i];
		}
		cout << t << "\n";
	}
	return 0;
}