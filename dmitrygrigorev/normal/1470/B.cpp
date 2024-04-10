#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const __int128 mod = (89578493570435905LL) + (ll) (rng() % 1000);
const __int128 prime = 2007;

const int N = 1e6 + 7;
vector<int> pd[N];
__int128 deg[N];

void precalc() {
	for (int i = 2; i < N; ++i) {
		if (!pd[i].size()) {
			for (int j = i; j < N; j += i) pd[j].pb(i);
		}
	}

	deg[0] = 1;
	for (int i = 1; i < N; ++i) {
		deg[i] = (deg[i-1] * prime) % mod;
	}

}



void solve() {

	int n;
	cin >> n;

	map<__int128, int> mask;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		__int128 H = 0;

		for (auto t : pd[x]) {
			int cnt = 0, Q = x;
			while (Q % t == 0) {
				cnt++;
				Q /= t;
			}

			if (cnt % 2 != 0) {
				H += deg[t];
				if (H >= mod) H -= mod;
			}

		}

		mask[H]++;

	}

	int mx = 0;
	int sum = 0;

	for (auto p : mask) {
		mx = max(mx, p.y);
		if (p.y % 2 == 0 || p.x == 0) sum += p.y;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		long long x;
		cin >> x;
		if (x == 0) cout << mx << '\n';
		else cout << max(mx, sum) << '\n';
	}

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	srand(time(NULL));

	precalc();

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}