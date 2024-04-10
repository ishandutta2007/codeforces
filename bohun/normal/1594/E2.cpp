#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int P = 1e9 + 7;
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
	if (b % 2)
	    res = res * a % P;
	a = a * a % P;
	b /= 2;
    }
    return res;
}

int n, k;
map<ll, int> m, cnt;

int f(string s) {
    char c = s[0];
    if (c == 'w' || c == 'y')
	return 0;
    if (c == 'r' || c == 'o')
	return 1;
    return 2;
}

vector<ll> solve(ll u, int dep) {
    if (cnt[u] == 0) {
	ll x = 2LL * power(4, (1LL << dep) - 2) % P;
	return {x, x, x};
    }
    vector<ll> dp(3, 2);
    if (m.count(u)) {
	dp[0] = dp[1] = dp[2] = 0;
	dp[m[u]] = 1;
    }
    if (dep == 1)
	return dp;
    auto L = solve(2 * u, dep - 1);
    auto R = solve(2 * u + 1, dep - 1);
    vector<vector<int>> v = {{1, 2}, {0, 2}, {0, 1}};
    rep(i, 0, 2) {
	int a = v[i][0];
	int b = v[i][1];
	dp[i] = dp[i] * (L[a] + L[b]) % P * (R[a] + R[b]) % P;
    }
    return dp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> k >> n;
    rep(i, 1, n) {
	ll u; string s;
	cin >> u >> s;
	m[u] = f(s);
	while (u) {
	    cnt[u]++;
	    u /= 2;
	}
    }
    auto res = solve(1, k);
    cout << (res[0] + res[1] + res[2]) % P;

    return 0;
}