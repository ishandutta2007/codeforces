#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < (n); )
#define rep1(i,n) for (int i = 0; ++i <= (n); )

namespace sol {

int main() {
    llong n; cin >> n;
    llong ans = 0;
    llong l = 1, r = n;
    while (l < r) {
        ans += (r + l) % (n + 1);
        ++l;
        if (l >= r) break;
        ans += (r + l) % (n + 1);
        --r;
    }
    cout << ans;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}