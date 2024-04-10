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
typedef unsigned long long ull;
const ll ma = 128 * 1024;


ll sum[100001], n, p;

int main() {
	iostream::sync_with_stdio(0);
	cin >> n >> p;
	forn (i, n) {
		ll a;
		cin >> a;
		sum[i + 1] = (sum[i] + a) % p;
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ans = max(ans, sum[i] + ((sum[n] - sum[i]) % p + p)%p);
	}
	cout << ans;
}