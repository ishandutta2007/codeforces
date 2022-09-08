/**
 *  created: 04/01/2021, 17:12:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m;
map<int, int> q;

bool solve() {
    int last = -1, tp = -1;
    for (auto p : q) {
        if (p.second == 3) {
            if (last != -1) {
                return false;
            }
            continue;
        }
        --p.second;
        if (last == -1) {
            last = p.first;
            tp = p.second;
        } else {
            if ((((p.first - last) % 2) ^ (tp ^ p.second)) == 0) {
                return false;
            }
            last = -1;
            tp = -1;
        }
    }
    return last == -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        q.clear();
        scanf("%d%d", &n, &m);
        while (m--) {
            int r, c;
            scanf("%d%d", &r, &c);
            --r;
            --c;
            q[c] |= 1 << r;
        }
        if (solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}