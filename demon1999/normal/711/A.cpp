#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) mp(mp(a, b), mp(c, d))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int szz = 10, buben = 3500000;

int n;
vector<string> s;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	s.resize(n);
	forn (i, n) cin >> s[i];
	forn (i, n) {
		if (s[i][0] == 'O' && s[i][1] == 'O') {
			cout << "YES\n";
			s[i][0] = s[i][1] = '+';;
			forn (i, n) cout << s[i] << "\n";
			re 0;
		}
		if (s[i][3] == 'O' && s[i][4] == 'O') {
			cout << "YES\n";
			s[i][3] = s[i][4] = '+';;
			forn (i, n) cout << s[i] << "\n";
			re 0;
		}
	}
	cout << "NO\n";
	re 0;
}