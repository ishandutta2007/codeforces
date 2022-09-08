#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;
const int max_x = 111, bits = 17;

int q, used[max_n];
vector<int> nxt[max_x][2], mn[max_x];

bool get_bit(int x, int pos) {
    return (bool) (x & (1 << pos));
}

void add_to_bor(int i) {
    mn[i].push_back(inf);
    nxt[i][0].push_back(0);
    nxt[i][1].push_back(0);
}

void add(int k, int x) {
    int cur = 0;
    for (int i = bits - 1; i >= 0; --i) {
        bool b = get_bit(x, i);
        if (nxt[k][b][cur] == 0) {
            nxt[k][b][cur] = mn[k].size();
            add_to_bor(k);
        }
        cur = nxt[k][b][cur];
        mn[k][cur] = min(mn[k][cur], x);
    }
}

void add(int x) {
    used[x] = 1;
    for (int k = 1; k < max_x; ++k) {
        if (x % k == 0) {
            add(k, x);
        }
    }
}

void init() {
    for (int i = 0; i < max_x; ++i) {
        add_to_bor(i);
    }
}

int solve1(int x, int k, int s) {
    s -= x;
    int res = -1;
    for (int v = k; v <= s; v += k) {
        if (used[v] && (res == -1 || (res ^ x) < (v ^ x))) {
            res = v;
        }
    }
    return res;
}

int solve2(int x, int k, int s) {
    s -= x;
    int cur = 0, res = 0;
    for (int i = bits - 1; i >= 0; --i) {
        bool ok = false;
        for (int j = 1; j >= 0; --j) {
            int b = get_bit(x, i) ^ j;
            if (nxt[k][b][cur] && mn[k][nxt[k][b][cur]] <= s) {
                cur = nxt[k][b][cur];
                res += (1 << i) * b;
                ok = true;
                break;
            }
        }
        if (!ok) {
            return -1;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    scanf("%d", &q);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int x;
            scanf("%d", &x);
            if (used[x] == 0) {
                add(x);
            }
        } else {
            int x, k, s;
            scanf("%d%d%d", &x, &k, &s);
            if (x % k) {
                printf("-1\n");
                continue;
            }
            if (k >= max_x) {
                printf("%d\n", solve1(x, k, s));
            } else {
                printf("%d\n", solve2(x, k, s));
            }
        }
    }
    return 0;
}