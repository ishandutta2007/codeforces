#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limite<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )
#define sz(v) ((int)v.size())

namespace sol {
#define maxn 111
    int n, w;
    int a[maxn], p[maxn], ans[maxn];

    bool cmpp(int u, int v) {
        return a[u] < a[v];
    }

    int main() {
        cin >> n >> w;
        rep(i, n) cin >> a[i], p[i] = i, ans[i] = 0;
        sort(p, p + n, cmpp);
        rep(i, n) {
            ans[p[i]] = (a[p[i]] + 1) / 2;
            w -= ans[p[i]];
        }
        if (w < 0) {
            cout << -1;
            return 0;
        }
        while (w > 0) {
            for (int i = n; i--; ) {
                if (ans[p[i]] < a[p[i]]) {
                    ++ans[p[i]];
                    --w;
                    break;
                }
            }
        }
        rep(i, n) cout << ans[i] << ' ';

        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--) 
        sol::main();
    return 0;
}