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
typedef pair<ll, ll> pll;
typedef long double ld;

ll l, n, p, t;
ll k[1000];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> l;
	forn (i, n) {
		string s;
		cin >> s;
		k[sz(s) - 1]++;
	}
	string s;
	cin >> s;
	ll ans = 0;
	forn (p, sz(s) - 1) {
		ans +=k[p];
	}
	ll mans = ans + 5 * (ans / l) + 1, an = ans + k[sz(s) - 1] + 5 * ((ans + k[sz(s) - 1] - 1) / l);
	cout << mans << " " << an; 
	re 0;
}