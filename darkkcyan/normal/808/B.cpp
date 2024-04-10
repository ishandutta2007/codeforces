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
#define maxn 201010
    int n, k;
    int a[maxn];

    int main() {
        cin >> n >> k;
        rep(i, n) cin >> a[i];
        llong s = 0;
        llong t = 0;
        rep(i, n) {
            s += a[i];
            if (i >= k - 1) {
                t += s;
                s -= a[i - k + 1];
            }
        }
        cout << fixed << setprecision(12) << ((long double) t / (n - k + 1)) << endl;

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