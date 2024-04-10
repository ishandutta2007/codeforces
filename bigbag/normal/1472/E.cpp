/**
 *  created: 04/01/2021, 16:51:07
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, ans[max_n];
pair<pair<int, int>, int> a[max_n], b[max_n];

void solve() {
    sort(b, b + n);
    int pos = 0, mn = inf, id = inf;
    for (int i = 0; i < n; ++i) {
        while (pos < n && b[pos].first.first < a[i].first.first) {
            if (mn > b[pos].first.second) {
                mn = b[pos].first.second;
                id = b[pos].second;
            }
            ++pos;
        }
        if (mn < a[i].first.second) {
            ans[a[i].second] = id;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].first.first, &a[i].first.second);
            a[i].second = i;
            ans[i] = -2;
            b[i] = a[i];
        }
        sort(a, a + n);
        solve();
        for (int i = 0; i < n; ++i) {
            swap(b[i].first.first, b[i].first.second);
        }
        solve();
        for (int i = 0; i < n; ++i) {
            printf("%d ", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}