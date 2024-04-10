#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

const int P = 998244353;
const int N = 1010;
int n, m;
ll a[N], b[N], in[N], alive[N];
vector<int> e[N];

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		e[i].clear();
		in[i] = 0;
	}

	rep(i, 1, m) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		in[b]++;
	}

	ll res = 0;
	rep(_, 0, 1000) {
		if (count(a + 1, a + n + 1, 0) == n) {
			cout << res << "\n";
			return;
		}
		rep(i, 1, n) b[i] = a[i];
		rep(i, 1, n) if (a[i]) b[i]--;
		rep(i, 1, n) for (auto x : e[i]) if (a[i] > 0) b[x]++;
		rep(i, 1, n) a[i] = b[i];
		res++;
	}

	rep(i, 1, n) a[i] %= P;
	rep(i, 1, n) alive[i] = 1;

	rep(_, 1, n) {
		pair<ll, int> mn = {4e18, 0};
		rep(i, 1, n) {
			if (in[i] == 0 && alive[i] == 1) {
				mn = min(mn, {a[i], i});
			}
		}
		if (mn.second == 0) break;
		for (auto x : e[mn.second])
			in[x]--;
		rep(i, 1, n) b[i] = a[i];
		rep(i, 1, n) if (alive[i]) b[i] = (b[i] + P - mn.first) % P;
		rep(i, 1, n) for (auto x : e[i]) if (alive[i]) b[x] = (b[x] + mn.first) % P;
		rep(i, 1, n) a[i] = b[i];
		res = (res + mn.first) % P;
		alive[mn.second] = 0;
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}