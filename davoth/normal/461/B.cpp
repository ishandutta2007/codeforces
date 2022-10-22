/// IN THE NAME OF METAL
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
ll A[MAXN], dp[2][MAXN], n;
vector<ll> adj[MAXN];

ll inv(ll x) {
    return Pow(x, MOD - 2, MOD);
}

void DFS(ll v) {
    if (sz(adj[v]) == 0) {
        if (A[v]) dp[0][v] = 1;
        else dp[1][v] = 1;
        return;
    }
    ll sum = 1;
    for (ll u : adj[v]) {
        DFS(u);
        sum = sum * (dp[0][u] + dp[1][u]) % MOD;   
    }
    if (A[v] == 0) dp[1][v] = sum;
    else {
        dp[0][v] = sum;
        return;
    }
    for (ll u : adj[v]) {       
        ll x = sum * inv((dp[0][u] + dp[1][u]) % MOD) % MOD;
        dp[0][v] = (dp[0][v] + x * dp[0][u] % MOD) % MOD;
    }
}

int main() {
    scanf("%lld", &n);
    for (ll i = 2, p; i <= n; i++) {
        scanf("%lld", &p);
        adj[p + 1].push_back(i);
    }
    for (ll i = 1; i <= n; i++) scanf("%lld", &A[i]);
    DFS(1);
    printf("%lld\n", dp[0][1]);
    return 0;
}