#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace Sol {

int main() {
    int n, m, k; cin >> n >> m >> k; --m;
    int a[n];
    rep(i, n) cin >> a[i];
    int ans = inf(int);
    rep(i, n) {
        if (a[i] == 0) continue;
        if (k < a[i]) continue;
        ans = min(ans, abs(i - m));
    }
    assert(ans != inf(int));
    cout << ans * 10;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}