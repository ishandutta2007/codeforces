#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> s, t;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; s.emplace_back(x, i);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; t.emplace_back(x, i);
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    vector<tuple<int, int, int>> ops;
    
    deque<pair<int, int>> to_solve;
    for (int i = 0; i < n; ++i) {
        int delta = t[i].first - s[i].first;
        if (delta == 0) continue;
        if (delta > 0) {
            to_solve.emplace_back(s[i].second, delta);
        } else {
            int now = -delta;
            while (now > 0) {
                if (to_solve.empty()) {
                    cout << "NO\n";
                    return 0;
                }
                if (now >= to_solve[0].second) {
                    ops.emplace_back(to_solve[0].first, s[i].second, 
                            to_solve[0].second);
                    now -= to_solve[0].second;
                    to_solve.pop_front();
                } else {
                    ops.emplace_back(to_solve[0].first, s[i].second, 
                            now);
                    to_solve[0].second -= now;
                    now = 0;
                }
            }
        }
    }
    if (to_solve.size()) {
        cout << "NO\n";
        return 0;
    }
    /*
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i].first == t[i].first) ++i;
        else if (s[j].first == t[j].first) --j;
        else {
            int a = t[i].first - s[i].first;
            int b = s[j].first - t[j].first;
            if (a < 0 || b < 0 || s[i].first > s[j].first) {
                cout << "NO\n";
                return 0;
            }
            int d = min(a, b);
            s[i].first += d; s[j].first -= d;
            ops.emplace_back(s[i].second, s[j].second, d);
        }
    }

    if (s[i].first != t[i].first) {
        cout << "NO\n";
        return 0;
    }
    */
    cout << "YES\n";
    cout << ops.size() << '\n';
    for (auto itr : ops) {
        int a, b, c; tie(a, b, c) = itr;
        cout << a + 1 << " " << b + 1 << " " << c << '\n';
    }

    return 0;
}