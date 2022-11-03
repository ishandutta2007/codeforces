#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

map<pair<string, int>, vector<pair<string, int>>> g;

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    pair<string, int> s;
    rep(i, 0, n) {
        pair<string, int> t;
        cin >> t.first >> t.second;
        if (i == 0) {
            s = t;
        }
        int k;
        cin >> k;
        rep(j, 0, k) {
            pair<string, int> x;
            cin >> x.first >> x.second;
            g[t].push_back(x);
        }
    }

    set<pair<string, int>> q1, q2;
    q1.insert(s);
    set<string> w;
    vector<pair<string, int>> ans;
    while (!q1.empty()) {
        for (auto it = q1.rbegin(); it != q1.rend(); ++it) {
            auto v = *it;
            if (w.count(v.first)) {
                continue;
            }
            w.insert(v.first);
            if (v.first != s.first) {
                ans.push_back(v);
            }
            for (auto &i : g[v]) {
                q2.insert(i);
            }
        }
        q1.clear();
        q1.swap(q2);
    }

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (auto& i : ans) {
        cout << i.first << " " << i.second << "\n";
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