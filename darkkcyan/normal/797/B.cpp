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

namespace sol {
// solution start here
int n;
vi o, e;

int main() {
    cin >> n;
    rep (i, n) {
        int t; cin >> t;
        if (t % 2 == 0) e.push_back(t);
        else o.push_back(t);
    }
    sort(e.rbegin(), e.rend());
    sort(o.rbegin(), o.rend());
    long tans = 0, ans = -inf(long);
    while (sz(e) and e.back() < 0) e.pop_back();
    for (auto i : e) tans += i;
    for (auto i : o) {
        tans += i;
        if (tans & 1) ans = max(ans, tans);
    }
    cout << ans;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}