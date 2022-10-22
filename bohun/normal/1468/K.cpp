#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n;
string s;

int updx(int x, char c) {
	if (c == 'L')
		return x - 1;
	if (c == 'R')
		return x + 1;
	return x;
}

int updy(int y, char c) {
	if (c == 'D')
		return y - 1;
	if (c == 'U')
		return y + 1;
	return y;
}

bool solve(int a, int b) {
	if (a == 0 && b == 0)
		return false;

	int x = 0, y = 0;
	rep(i, 0, n) {
		if (!(updx(x, s[i]) == a && updy(y, s[i]) == b)) {
			x = updx(x, s[i]);
			y = updy(y, s[i]);
		}
	}

	return x == 0 && y == 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.length();

		int x = 0, y = 0;
		pair<int, int> res = {0, 0};
		rep(i, 0, n) {
			x = updx(x, s[i]);
			y = updy(y, s[i]);
			if (solve(x, y))
				res = {x, y};
		}

		cout << res.first << " " << res.second << "\n";
	}

	return 0;
}