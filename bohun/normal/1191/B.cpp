//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

string s[3];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> s[0] >> s[1] >> s[2];
	sort(s, s + 3);

	int res = 2;
	if (s[0] == s[2])
		res = 0;
	if (s[0] == s[1] || s[1] == s[2])
		res = min(res, 1);

	FOR(i, 3)
		swap(s[i][0], s[i][1]);
	sort(s, s + 3);

	auto f = [&](int i) {
		return s[i][0] == s[i + 1][0] && s[i][1] + 1 == s[i + 1][1];
	};
	auto g = [&](int i) {
		return s[i][0] == s[i + 1][0] && s[i][1] + 2 == s[i + 1][1];
	};
	if (f(0) && f(1))
		res = 0;
	if (g(0) || g(1) || f(0) || f(1))
		res = min(res, 1);

	cout << res << '\n';
	return 0;
}