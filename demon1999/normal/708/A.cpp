#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> s;
	int nu0 = sz(s);
	forn (i, sz(s))
		if (s[i] != 'a') {
			nu0 = i;
			break;
		}
	if (nu0 == sz(s))
		s[sz(s) - 1] = 'z';
	for (int i = nu0; i < sz(s); i++) {
		if (s[i] == 'a') break;
		s[i] = char(s[i] - 1);
	}
	cout << s;
	re 0;
}