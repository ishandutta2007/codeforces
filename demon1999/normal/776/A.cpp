#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 2 * 16 * 1024;

int n;
string s, t;
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> s >> t;
	cin >> n;
	cout << s << " " << t << "\n";
	forn (i, n) {
		string p, q;
		cin >> p >> q;
		if (s == p)
			s = q;
		else
			t = q;
		cout << s << " " << t << "\n";
	}
	
}