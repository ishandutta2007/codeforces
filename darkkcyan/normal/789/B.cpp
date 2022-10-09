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
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {

long b, q, l, n;
set<int> a;

int main() {
    cin >> b >> q >> l >> n;
    int t; rep(i, n) cin >> t, a.insert(t);
    int ans = 0;
    long step = 0;
    long ms = 1e5;
    while (abs(b) <= l) {
        if (++step > ms) break;
        if (!a.count(b)) ++ans;
        b *= q;
    }
    if (step > ms) {
        if (ans == 0) cout << 0;
        else {
            long oa = ans;
            step = 0;
            while (abs(b) <= l) {
                if (++step > ms) break;
                if (!a.count(b)) ++ans;
                b *= q;
            }
            if (ans == oa) cout << ans;
            else cout << "inf";
        }
    } else cout << ans;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}