/**
 *  created: 03/04/2021, 18:41:32
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], b[max_n];
set<pair<int, int>> all;

void wa() {
    puts("-1");
    exit(0);
}

int proc() {
    int mn = all.begin()->first;
    int mx = all.rbegin()->first;
    int a1 = -inf, b1 = inf;
    int a2 = inf, b2 = -inf;
    int sz = 0, res = 0;
    while (!all.empty()) {
        {
            auto it = all.begin();
            if (sz == 0 || mn + sz > it->first) {
                const int id = it->second;
                const int mn = min(a[id], b[id]), mx = max(a[id], b[id]);
                res += it->first != a[id];
                if (a1 > mn || a2 < mx) {
                    wa();
                }
                a1 = mn;
                a2 = mx;
                //cout << mn << " " << mx << " to the begin" << endl;
                all.erase({a[id], id});
                all.erase({b[id], id});
                ++sz;
                continue;
            }
        }
        {
            auto it = --all.end();
            if (mx - sz < it->first) {
                const int id = it->second;
                const int mn = min(a[id], b[id]), mx = max(a[id], b[id]);
                res += it->first != a[id];
                if (b1 < mx || b2 > mn) {
                    wa();
                }
                //cout << mx << " " << mn << " to the end" << endl;
                b1 = mx;
                b2 = mn;
                all.erase({a[id], id});
                all.erase({b[id], id});
                ++sz;
                continue;
            }
        }
        break;
    }
    if (a1 < b1 && a2 > b2) {
        return min(res, sz - res);
    }
    wa();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        all.insert({a[i], i});
        all.insert({b[i], i});
    }
    int ans = 0;
    while (!all.empty()) {
        ans += proc();
    }
    printf("%d\n", ans);
    return 0;
}