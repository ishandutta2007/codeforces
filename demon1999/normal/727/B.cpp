#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

ll ans = 0;

void plus1(string s) {
	if (sz(s) == 0) re;
	ll sum = 0, sum1 = 0;
	if (sz(s) >= 3 && s[sz(s) - 3] == '.') {
		sum += (s[sz(s) - 2] - '0') * 10 + (s[sz(s) - 1] - '0');
		forn (i, 3)
			s.pop_back();
	}
	forn (i, sz(s)) {
		if (s[i] == '.')
			continue;
		sum1 = sum1 * 10LL + ll(s[i] - '0');
	}
	ans += sum + sum1 * 100LL;
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	string s, s1 = "";
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] != '.' && (s[i] < '0' || s[i] > '9')) {
			plus1(s1);
			s1 = "";
			continue;
		}
		s1 += s[i];
	}
	plus1(s1);
	string anss = "", pls = "";
	if (ans % 100) {
		pls = ".";
		pls += char((ans % 100) / 10 + '0');
		pls += char((ans % 10) + '0');
	}
	ans /= 100;
	if (ans == 0)
		anss = "0";
	while (ans) {
		anss += char(ans % 10 + '0');
		ans /= 10;
		if (sz(anss) >= 3 && ans && anss[sz(anss) - 3] != '.' && anss[sz(anss) - 2] != '.' && anss[sz(anss) - 1] != '.')
			anss += ".";
	}
	reverse(anss.begin(), anss.end());
	cout << anss << pls << "\n";
	re 0;
}