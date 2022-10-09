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

    int digcnt(llong x) {
        if (x <= 9) return 1;
        return digcnt(x / 10) + 1;
    }

    int main() {
        llong n;
        cin >> n;
        int dc = digcnt(n);
        llong t = n;
        rep(i, dc - 1) t /= 10;
        ++t;
        rep(i, dc - 1) t *= 10;
        cout << t - n;
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