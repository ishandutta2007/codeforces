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
ll A[MAXN], n, ans = 0;
int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    sort(A + 1, A + n + 1);
    for (ll i = 1; i <= n; i++) {
        if (i == n) ans += A[i] * n;
        else ans += A[i] * (i + 1);
    }
    printf("%lld\n", ans);
    return 0;
}