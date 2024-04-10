#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int ma = 1024 * 1024 * 2;

ll n, k;
vector<ll> a;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> k;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	forn (i, n) {
		if ((a[i] - a[0]) % k != 0) {
			cout << -1;
			re 0;
		}
		ans += (a[i] - a[0]) / k;
	}
	cout << ans;
	re 0;
}