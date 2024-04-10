#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int t, n, a[max_n], nxt[max_n], used[max_n];

void solve() {
    int v = 1;
    while (!used[v]) {
        used[v] = 1;
        v = nxt[v];
    }
    while (used[v] != 2) {
        used[v] = 2;
        v = nxt[v];
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 2) {
            ans.push_back(i);
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            nxt[i] = i - a[i];
            used[i] = 0;
        }
        solve();
    }
    return 0;
}