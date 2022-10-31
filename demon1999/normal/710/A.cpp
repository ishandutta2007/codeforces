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

int c1, c2;
string s;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> s;
	if (s[0] == 'a' || s[0] == 'h')
		c1 = 1;
	if (s[1] == '1' || s[1] == '8')
		c2 = 1;
	if (c1 && c2) cout << 3;
	else
		if (c1 || c2) cout << 5;
		else
			cout << 8;
	re 0;
}