#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 1000000000, ss = 8 * 1024;
int n, k, ans, ma1 = -1, ma2 = -1, nu = -1;
unordered_map<int, int> pp;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sumb.out", "w", stdout);
	cin >> n;
	vector<int> a(n, 0);
	pp.rehash(600000);
	forn (i, n) {
		cin >> a[i];
		pp[a[i]]++;
	}
	
	cin >> k;
	vector<int>  b(k, 0), c(k, 0);
	forn (i, k) {
		cin >> b[i];
	}
	forn (i, k) cin >> c[i];
	forn (i, k) {
		int k1 = pp[b[i]], k2 = pp[c[i]];
		//cout << ma1 << " " << ma2 << endl;
		//cout << k1 << " " << k2 << endl;
		if (k1 > ma1 || (k1 == ma1 && k2 > ma2)) {
			ma1 = k1; ma2 = k2; nu = i + 1;
		}
	}
	cout << nu;
	re 0;
}