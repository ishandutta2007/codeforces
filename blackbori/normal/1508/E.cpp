#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[303030], I[303030], O[303030], D[303030], N[303030];
ll B[303030], P[303030], S[303030], C[303030];
vector<ll> G[303030];
ll n, t, a, in, on;

void die() { cout << "NO\n"; exit(0); }

void dfs(ll u) {
	I[++in] = u; N[u] = in;
	for (ll &v: G[u]) {
		D[v] = D[u] + 1; dfs(v);
	}
	O[++on] = u;
}

void tc() {
	ll i, j, u, v;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i]; B[A[i]] = i;
	}
	for (i = 1; i < n; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		P[v] = u; S[u] ++;
	}

	for (i = 1; i <= n; i++) {
		if (S[B[i]]) break;
		S[P[B[i]]]--;
	}

	t = i;
	for (i = B[t]; P[i]; i = P[i]) {
		if (A[i] > A[P[i]]) die();
		for (auto &v: G[P[i]]) {
			if (v == i) continue;
			if (A[i] < A[v] && A[v] < A[P[i]]) die();
		}
		swap(A[i], A[P[i]]); a++;
	}

	for (i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end(), [&](ll a, ll b) {
			return A[a] < A[b];
		});
	}

	dfs(1);

	for (i = 1; i < t; i++) {
		if (A[O[i]] != i) die();
		C[O[i]] = 1;
	}

	for (i = 1, j = 0; i <= n; i++) {
		if (!C[I[i]]) {
			if (A[I[i]] != t + j) die();
			j++;
		}
	}

	for (i = 1; i <= n; i++) {
		if (A[i] < t) a += D[i];
	}

	cout << "YES\n";
	cout << a << "\n";
	for (i = 1; i <= n; i++) {
		cout << N[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}