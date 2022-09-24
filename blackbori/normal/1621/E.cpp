#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct tree {
	int T[1101010];
	int V[1101010];

	void init(int p, int s, int e) {
		T[p] = V[p] = 0;
		if (s < e) {
			init(p << 1, s, s + e >> 1);
			init(p << 1 | 1, s + e + 2 >> 1, e);
		}
	}

	void add(int p, int s, int e, int l, int r, int v) {
		if (r < s || e < l) return;
		else if (l <= s && e <= r) {
			T[p] += v; V[p] += v;
		}
		else {
			add(p << 1, s, s + e >> 1, l, r, v);
			add(p << 1 | 1, s + e + 2 >> 1, e, l, r, v);
			T[p] = min(T[p << 1], T[p << 1 | 1]) + V[p];
		}
	}
} T;

vector<ll> V[101010];
ll A[101010], S[101010];
ll n, m;

void tc() {
	vector<ll> X;
	ll i, j, k, x, t;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		X.push_back(A[i]);
	}

	for (i = 1; i <= m; i++) {
		cin >> k; S[i] = 0;
		V[i].clear();
		for (j = 0; j < k; j++) {
			cin >> x; V[i].push_back(x);
			S[i] += x;
		}
		X.push_back((S[i] + k - 1) / k);
		for (auto &t: V[i]) {
			X.push_back((S[i] - t + k - 2) / (k - 1));
		}
	}

	sort(X.begin(), X.end());
	// for (ll &t: X) cout << t << " ";
	// cout << "\n";
	X.erase(unique(X.begin(), X.end()), X.end());
	T.init(1, 0, X.size() - 1);

	for (i = 1; i <= n; i++) {
		t = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
		T.add(1, 0, X.size() - 1, 0, t, 1);
		//cout << "*" << t << endl;
	}
	for (i = 1; i <= m; i++) {
		k = V[i].size();
		t = lower_bound(X.begin(), X.end(), (S[i] + k - 1) / k) - X.begin();
		T.add(1, 0, X.size() - 1, 0, t, -1);
		//cout << "*" << t << endl;
	}

	for (i = 1; i <= m; i++) {
		k = V[i].size();
		t = lower_bound(X.begin(), X.end(), (S[i] + k - 1) / k) - X.begin();
		T.add(1, 0, X.size() - 1, 0, t, 1);
		for (auto &t: V[i]) {
			ll y = lower_bound(X.begin(), X.end(), (S[i] - t + k - 2) / (k - 1)) - X.begin();
//			cout << "*" << y << endl;
			T.add(1, 0, X.size() - 1, 0, y, -1);
			cout << (T.T[1] >= 0);
			T.add(1, 0, X.size() - 1, 0, y, 1);
		}
		T.add(1, 0, X.size() - 1, 0, t, -1);
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}