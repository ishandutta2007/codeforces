#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define x first
#define y second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
map<ll, ll> kk; 
vector<ll> a;

ll ans = 0;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	ll a;
	forn (ii, n) {
		cin >> a;
		ll aa = a;
		ll cc = 0;
		ll i = 0;
		for (; i < 60; i++) {
			if (a & (1LL << i)) {
				cc += (1LL << i);
				a -= (1LL << i);
				i++;
				break;
			}
		}
		for (; a; i++) {
			if (a & (1LL << i)) {
				a -= (1LL << i);
			}
			else
				cc += (1LL << i);
		}
		for (; i < 60; i++) {
			ans += kk[cc];
			cc |= (1LL << i);
			//cout << cc << " " << kk[cc] << endl;
		}
		kk[aa]++;
	}
	cout << ans;
 	re 0;
}