#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long n, x; cin >> n >> x;

    static ve<long> a(101010);
    for (int i = 0; i < n; ++i) {
        long u; cin >> u;
        a[u]++;
    }

    long ans = 0;
    for (int i = 0; i < sz(a); ++i) {
        if (!a[i]) continue;
        long t = x ^ i;
        if (t > sz(a)) continue;
        if (t == i) ans += a[i] * (a[i] - 1) / 2;
        else ans += a[i] * a[t];
        a[t] = 0;
    }

    cout << ans;

    return 0;
}