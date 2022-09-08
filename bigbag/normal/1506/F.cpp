/**
 *  created: 25/03/2021, 17:07:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
pair<int, int> p[max_n];

int solve(int x, int y, int x2, int y2) {
    int c = y2 - y;
    int tot = x2 - x;
    assert(c <= tot);
    if ((x + y) % 2) {
        return (tot - c + 1) / 2;
    }
    if (c == tot) {
        return c;
    }
    return (tot - c) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cout << solve(3, 2, 5, 2) << endl;
    //cout << solve(5, 2, 8, 4) << endl;
    //return 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ++n;
        p[0] = {1, 1};
        for (int i = 1; i < n; ++i) {
            scanf("%d", &p[i].first);
        }
        for (int i = 1; i < n; ++i) {
            scanf("%d", &p[i].second);
        }
        sort(p, p + n);
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            ans += solve(p[i].first, p[i].second, p[i + 1].first, p[i + 1].second);
        }
        printf("%d\n", ans);
    }
    return 0;
}