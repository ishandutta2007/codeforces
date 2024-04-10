#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 300333, inf = 1011111111;

int n, pos[3];
vector<int> all[3];
vector<int> v[3];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int get_tot(int mask) {
    int mn = inf, mx = -inf;
    for (int i = 0; i < 3; ++i) {
        if (get_bit(mask, i) && all[i].size()) {
            mn = min(mn, all[i][0]);
            mx = max(mx, all[i].back());
        }
    }
    if (mn == inf) {
        return 0;
    }
    return mx - mn;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        char tp;
        scanf("%d%c%c", &x, &tp, &tp);
        if (tp == 'G') {
            all[0].push_back(x);
        } else if (tp == 'R') {
            all[1].push_back(x);
        } else {
            all[2].push_back(x);
        }
    }
    for (int i = 0; i < 3; ++i) {
        sort(all[i].begin(), all[i].end());
    }
    int ans = get_tot(3) + get_tot(5);
    for (int i = 0; i + 1 < all[0].size(); ++i) {
        int l = all[0][i], r = all[0][i + 1];
        int economy = 0;
        for (int tp = 1; tp < 3; ++tp) {
            v[tp].clear();
            v[tp].push_back(l);
            while (pos[tp] < all[tp].size() && all[tp][pos[tp]] < l) {
                ++pos[tp];
            }
            while (pos[tp] < all[tp].size() && all[tp][pos[tp]] < r) {
                v[tp].push_back(all[tp][pos[tp]]);
                ++pos[tp];
            }
            v[tp].push_back(r);
            int mx = 0;
            for (int j = 0; j + 1 < v[tp].size(); ++j) {
                mx = max(mx, v[tp][j + 1] - v[tp][j]);
            }
            economy += mx;
        }
        if (r - l < economy) {
            ans -= economy;
            ans += r - l;
        }
    }
    printf("%d\n", ans);
    return 0;
}