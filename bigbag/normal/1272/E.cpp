#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], ans[max_n];
vector<int> rg[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(ans, -1, sizeof(ans));
    scanf("%d", &n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i - a[i] >= 0) {
            rg[i - a[i]].push_back(i);
            if (a[i - a[i]] % 2 != a[i] % 2) {
                ans[i] = 1;
            }
        }
        if (i + a[i] < n) {
            rg[i + a[i]].push_back(i);
            if (a[i + a[i]] % 2 != a[i] % 2) {
                ans[i] = 1;
            }
        }
        if (ans[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : rg[v]) {
            if (ans[to] == -1 && a[to] % 2 == a[v] % 2) {
                ans[to] = ans[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}