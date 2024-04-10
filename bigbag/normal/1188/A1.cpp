#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n, sz[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++sz[u];
        ++sz[v];
    }
    for (int i = 1; i <= n; ++i) {
        if (sz[i] == 2) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}