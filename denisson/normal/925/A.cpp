#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

void solve(istream& cin, ostream& cout) {
    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    set<int> ls;
    rep(i, 0, cl) {
        int x;
        cin >> x;
        ls.insert(x);
    }
    set<int> es;
    rep(i, 0, ce) {
        int x;
        cin >> x;
        es.insert(x);
    }
    int q;
    cin >> q;
    rep(iq, 0, q) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2) << "\n";
            continue;
        }
        auto it = ls.lower_bound(y1);
        int ans = 2e9;
        if (ls.size() > 0 && it != ls.end()) {
            int t = *it;
            int c = abs(y1 - t);
            c += abs(x1 - x2);
            c += abs(t - y2);
            ans = min(ans, c);
        }
        if (ls.size() > 0 && it != ls.begin()) {
            --it;
            int t = *it;
            int c = abs(y1 - t);
            c += abs(x1 - x2);
            c += abs(t - y2);
            ans = min(ans, c);
        }

        auto ie = es.lower_bound(y1);
        if (es.size() > 0 && ie != es.end()) {
            int t = *ie;
            int c = abs(y1 - t);
            c += (abs(x1 - x2) + v - 1) / v;
            c += abs(y2 - t);
            ans = min(ans, c);
        }
        if (es.size() > 0 && ie != es.begin()) {
            --ie;
            int t = *ie;
            int c = abs(y1 - t);
            c += (abs(x1 - x2) + v - 1) / v;
            c += abs(y2 - t);
            ans = min(ans, c);
        }
        cout << ans << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}