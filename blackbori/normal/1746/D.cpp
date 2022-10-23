#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> T[202020];
map<ll, ll> M[202020];
ll P[202020], S[202020];
ll n, k;

ll f(ll u, ll k) {
	if (k == 0) return 0;
	if (M[u].find(k) != M[u].end()) return M[u][k];

	ll s = S[u] * k;
	if (T[u].empty()) return M[u][k] = s;
	if (T[u].size() == 1) return M[u][k] = s + f(T[u][0], k);

	ll t = k / T[u].size(), r = k % T[u].size();
	vector<ll> V;

	for (auto &v: T[u]) {
		s += f(v, t);
		V.emplace_back(f(v, t + 1) - f(v, t));
	}
	sort(V.rbegin(), V.rend());
	for (; r--; ) s += V[r];

	return M[u][k] = s;
}

void tc() {
	ll i;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		T[i].clear(); M[i].clear();
	}
	for (i = 2; i <= n; i++) {
		cin >> P[i];
		T[P[i]].push_back(i);
	}
	for (i = 1; i <= n; i++) {
		cin >> S[i];
	}
	cout << f(1, k) << "\n";
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