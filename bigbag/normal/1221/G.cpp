#include <bits/stdc++.h>

using namespace std;

const int max_n = 41, inf = 1000111222;
const int max_sz = 20;

int n, m, cnt[1 << max_sz], mask_to[max_n];
long long pw[max_n];
vector<int> g[max_n], gl[max_n], gr[max_n], glr[max_n];
int sz, szr;

bool isl(int v) {
    return v < sz;
}

bool isr(int v) {
    return !isl(v);
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

long long no0() {
    memset(cnt, 0, sizeof(cnt));
    for (int mask = 0; mask < (1 << szr); ++mask) {
        bool ok = true;
        for (int i = sz; i < n && ok; ++i) {
            if (!get_bit(mask, i - sz)) {
                for (int to : gr[i]) {
                    if (!get_bit(mask, to - sz)) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) {
            //++cnt[(1 << szr) - 1 - mask];
            ++cnt[ mask];
        }
    }
    for (int i = 0; i < szr; ++i) {
        for (int mask = 0; mask < (1 << szr); ++mask) {
            if (get_bit(mask, i)) {
                cnt[mask ^ (1 << i)] += cnt[mask];
            }
        }
    }
    long long res = 0;
    for (int mask = 0; mask < (1 << sz); ++mask) {
        bool ok = true;
        for (int i = 0; i < sz && ok; ++i) {
            if (!get_bit(mask, i)) {
                for (int to : gl[i]) {
                    if (!get_bit(mask, to)) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) {
            int mto = 0;
            for (int i = 0; i < sz; ++i) {
                if (!get_bit(mask, i)) {
                    mto |= mask_to[i];
                }
            }
            res += cnt[mto];
            //res += cnt[(1 << szr) - 1 - mto];
        }
    }
    return res;
}

int used[max_n];

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

bool dfs1(int v, int col) {
    used[v] = col;
    for (int to : g[v]) {
        if (used[to] == -1) {
            if (!dfs1(to, col ^ 1)) {
                return false;
            }
        } else if (used[to] != (col ^ 1)) {
            return false;
        }
    }
    return true;
}

long long no1() {
    memset(used, 0, sizeof(used));
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
            res *= 2;
        }
    }
    return res;
}

long long no2() {
    return no0();
}

long long only0() {
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        if (g[i].empty()) {
            res *= 2;
        }
    }
    return res;
}

long long only1() {
    memset(used, -1, sizeof(used));
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            if (!dfs1(i, 0)) {
                return 0;
            }
            res *= 2;
        }
    }
    return res;
}

long long only2() {
    return only0();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }
    sz = max(1, n / 2);
    szr = n - sz;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (isl(u) && isl(v)) {
            gl[u].push_back(v);
        } else if (isr(u) && isr(v)) {
            gr[u].push_back(v);
            //?
        } else {
            if (isl(v)) {
                swap(u, v);
            }
            glr[u].push_back(v);
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int to : glr[i]) {
            mask_to[i] |= 1 << (to - sz);
        }
    }
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
    long long ans = pw[n];
    ans -= 2 * no0();
    ans -= no1();
    //ans -= no2();
    ans += only0();
    ans += only1();
    ans += only2();
    cout << ans << endl;
    return 0;
}