#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;
const int max_b = 30;
const int max_v = max_n * max_b;

int n, a[max_n], dp[max_v];
int first, nxt[max_v][2];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void add(int x) {
    int v = 0;
    for (int i = max_b - 1; i >= 0; --i) {
        int c = get_bit(x, i);
        if (!nxt[v][c]) {
            nxt[v][c] = ++first;
        }
        v = nxt[v][c];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        add(a[i]);
    }
    for (int v = first; v >= 0; --v) {
        vector<int> g;
        for (int i = 0; i < 2; ++i) {
            if (nxt[v][i]) {
                g.push_back(nxt[v][i]);
            }
        }
        if (g.empty()) {
            dp[v] = 1;
        } else if (g.size() == 1) {
            dp[v] = dp[g[0]];
        } else {
            dp[v] = max(dp[g[0]], dp[g[1]]) + 1;
        }
    }
    printf("%d\n", n - dp[0]);
    return 0;
}