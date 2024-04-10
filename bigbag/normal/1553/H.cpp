/**
 *  created: 24/07/2021, 11:07:05
**/

#include <bits/stdc++.h>

using namespace std;

const int max_k = 19;
const int max_n = (1 << max_k) + 5, inf = 1000111222;
const int max_v = max_n * max_k;

int n, k, a[max_n], ans[max_k][max_n];
int first, nxt[max_v][2];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void add(int x) {
    int v = 0;
    for (int i = k - 1; i >= 0; --i) {
        if (!nxt[v][get_bit(x, i)]) {
            nxt[v][get_bit(x, i)] = ++first;
        }
        v = nxt[v][get_bit(x, i)];
    }
}

int get_min(int v, int k, int x) {
    int res = 0;
    for (int i = k; i >= 0; --i) {
        int f = get_bit(x, i);
        if (!nxt[v][f]) {
            res ^= 1 << i;
            f ^= 1;
        }
        assert(nxt[v][f]);
        v = nxt[v][f];
    }
    return res;
}

int get_max(int v, int k, int x) {
    int res = 0;
    for (int i = k; i >= 0; --i) {
        int f = !get_bit(x, i);
        res ^= 1 << i;
        if (!nxt[v][f]) {
            res ^= 1 << i;
            f ^= 1;
        }
        assert(nxt[v][f]);
        v = nxt[v][f];
    }
    return res;
}

void solve(int v, int lev) {
    const int max_x = 1 << (lev + 1);
    fill(ans[lev], ans[lev] + max_x, inf);
    if (!lev) {
        if (nxt[v][0] && nxt[v][1]) {
            ans[lev][0] = 1;
            ans[lev][1] = 1;
        }
        return;
    }
    for (int i = 0; i < 2; ++i) {
        if (nxt[v][i]) {
            solve(nxt[v][i], lev - 1);
            for (int x = 0; x < max_x; ++x) {
                ans[lev][x] = min(ans[lev][x], ans[lev - 1][x & ((max_x - 1) ^ (1 << lev))]);
            }
        }
    }
    if (nxt[v][0] && nxt[v][1]) {
        for (int x = 0; x < max_x; ++x) {
            const int f = !get_bit(x, lev);
            ans[lev][x] = min(ans[lev][x], get_min(nxt[v][f], lev - 1, x) + (1 << lev) - get_max(nxt[v][!f], lev - 1, x));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        add(a[i]);
    }
    solve(0, k - 1);
    for (int i = 0; i < (1 << k); ++i) {
        printf("%d ", ans[k - 1][i]);
    }
    puts("");
    return 0;
}