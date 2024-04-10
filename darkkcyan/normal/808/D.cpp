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
#define maxn 101010
    int n;
    int a[maxn];
    multiset<llong> pre, suf;


    int main() {
#define quit(msg) cout << msg, exit(0)
        cin >> n;
        llong ps, ss; ps = ss = 0;
        rep(i,n) cin >> a[i], suf.insert(a[i]), ss += a[i];
        if (ss & 1) quit("NO");
        
        rep(i, n) {
            //if (ps == ss) quit("YES");
            if (ps > ss) {
                llong t = (ps - ss) / 2;
                if (pre.count(t)) quit("YES");
            } else {
                llong t = (ss - ps) / 2;
                if (suf.count(t)) quit("YES");
            }
            ps += a[i];
            ss -= a[i];
            suf.erase(suf.find(a[i]));
            pre.insert(a[i]);
        }
        quit("NO");

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