#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod1 = rand() % 1488 + 1000000000, p1 = 179;
const int mod2 = rand() % 1488 + 1000000000, p2 = 239; 

vector<pair<int, int> > code;

bool cmp(int x, int y) {
	return (code[x] < code[y]);
}

int pw(int x, int y, int mod) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * pw(x, y-1, mod)) % mod;
	int t = pw(x, y/2, mod);
	return ((ll) t * t) % mod;
}
ll gcd(ll x, ll y) {
	if (y==0) return x;
	return gcd(y, x%y);
}

void solve() {
	int n, m;
	cin >> n >> m;

	code.assign(n, {0, 0});

	vector<ll> w(n);
	for (int i = 0; i < n; ++i) cin >> w[i];

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		code[v].first += pw(p1, u, mod1);
		code[v].first %= mod1;

		code[v].second += pw(p2, u, mod2);
		code[v].second %= mod2;

	}

	vector<int> tet;
	for (int i = 0;i<n;++i) tet.push_back(i);
	sort(tet.begin(), tet.end(), cmp);
	int start = 0;
	ll ans = 0;

	while (start < n) {
		int finish = start;
		ll sum = 0;
		while (finish < n && code[tet[start]] == code[tet[finish]]) {
			sum += w[tet[finish++]];
		}

		if (code[tet[start]] != make_pair(0, 0)) ans = gcd(ans, sum);
		start = finish;

	}
	//cout << endl;

	cout << ans << "\n";

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}