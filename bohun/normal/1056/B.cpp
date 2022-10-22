//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int n, m;
ll cnt[1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	FOR(i, m)
		cnt[i] = n / m + (i > 0 && i <= n % m);

	ll res = 0;
	FOR(i, m)
		FOR(j, m)
			if ((i * i + j * j) % m == 0)
				res += cnt[i] * cnt[j];

	cout << res << '\n';

	return 0;
}