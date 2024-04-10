#include <bits/stdc++.h>

using namespace std;

namespace sol {

#define iint long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

ve<string> a, b;
int n;

int main() {
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];

    int ans = inf(int);
    rep(i, n) {
        b = a;
        int tans = 0;
        rep(f, n) {
            int ms = sz(b[i]);
            while (b[i] != b[f]) {
                b[f] += b[f][0];
                b[f].erase(0, 1);
                ++tans;
                if (--ms == -1) {
                    cout << -1;
                    exit(0);
                }
            }
        }
        ans = min(ans, tans);
    }
    cout << ans;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}