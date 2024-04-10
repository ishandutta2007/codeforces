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
vector<pair<ll, ll> > qq, pp;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0;
	vector<ll> kk;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B' && (i == 0 || s[i] != s[i - 1])) {
			ans++;
			kk.push_back(0);
		}
		if (s[i] == 'B')
			kk[sz(kk) - 1]++;
	}
	cout << ans << "\n";
	forn (i, ans)
		cout << kk[i] << " ";
	re 0;
}