#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = - 1; ++i < (n);)
#define rep1(i,n) for (int i = 0; ++i <= (n); )

namespace sol {

llong p, x, y;

bool can(llong s) {
    llong i = (s / 50) % 475;
    rep(nolove, 25) {
        i = (i * 96 + 42) % 475;
        if (i + 26 == p) return 1;
    }
    return 0;
}

int main() {
    cin >> p >> x >> y;
#define quit(ans) { return cout << ans, 0; }
    llong t = x;
    while (t >= y) {
        if (can(t)) quit(0);
        t -= 50;
    }
    for (llong ans = 1; ans < 1e7; ++ans) {
        t = x + ans * 100;
        if (t >= y and can(t)) quit(ans);
        t -= 50;
        if (t >= y and can(t)) quit(ans);
    }
    assert(0);
    return 0;
} }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--)
    sol::main();
    return 0;
}