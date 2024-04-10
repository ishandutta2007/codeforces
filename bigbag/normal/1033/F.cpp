#include <bits/stdc++.h>

using namespace std;

const int max_n = 30033, inf = 1000111222;
const int max_mask = 555555;

int w, n, m, a[max_n], dp[max_mask], mx, cnt[5555];
char op[15];
int tol[77], tor[77];

int to3(int x) {
    vector<int> v;
    for (int i = 0; i < w; ++i) {
        v.push_back(x % 2);
        x /= 2;
    }
    reverse(v.begin(), v.end());
    int mask = 0;
    for (int i = 0; i < w; ++i) {
        mask = mask * 3 + v[i];
    }
    return mask;
}

int set_bit(int x, int pos) {
    vector<int> v;
    for (int i = 0; i < w; ++i) {
        v.push_back(x % 3);
        x /= 3;
    }
    reverse(v.begin(), v.end());
    v[pos] = 2;
    int mask = 0;
    for (int i = 0; i < w; ++i) {
        mask = mask * 3 + v[i];
    }
    return mask;
}

bool get_b3(int x, int pos) {
    vector<int> v;
    for (int i = 0; i < w; ++i) {
        v.push_back(x % 3);
        x /= 3;
    }
    reverse(v.begin(), v.end());
    return v[pos] == 2;
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int get(char tp, int b) {
    if (tp == 'A') {
        if (b == 0) {
            return 2;
        }
        return 0;
    }
    if (tp == 'O') {
        if (b == 0) {
            return 0;
        }
        return -1;
    }
    if (tp == 'X') {
        return b;
    }
    if (tp == 'a') {
        if (b == 0) {
            return -1;
        }
        return 1;
    }
    if (tp == 'o') {
        if (b == 0) {
            return 1;
        }
        return 2;
    }
    if (tp == 'x') {
        return 1 - b;
    }
    exit(228);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &w, &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++dp[to3(a[i])];
        ++cnt[a[i]];
    }
    mx = 1;
    for (int i = 0; i < w; ++i) {
        mx *= 3;
    }
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < mx; ++i) {
            if (!get_b3(i, j)) {
                dp[set_bit(i, j)] += dp[i];
            }
        }
    }
    int l = (w + 1) / 2;
    int r = w - l;
    while (m--) {
        scanf("%s", op);
        for (int mask = 0; mask < (1 << l); ++mask) {
            tol[mask] = 0;
            for (int i = 0; i < l; ++i) {
                bool b = get_bit(mask, l - 1 - i);
                char tp = op[i];
                int y = get(tp, b);
                if (y == -1) {
                    tol[mask] = -1;
                    break;
                }
                tol[mask] = tol[mask] * 3 + y;
            }
        }
        for (int mask = 0; mask < (1 << r); ++mask) {
            tor[mask] = 0;
            for (int i = 0; i < r; ++i) {
                bool b = get_bit(mask, r - 1 - i);
                char tp = op[l + i];
                int y = get(tp, b);
                if (y == -1) {
                    tor[mask] = -1;
                    break;
                }
                tor[mask] = tor[mask] * 3 + y;
            }
        }
        int MUL = 1;
        for (int i = 0; i < r; ++i) {
            MUL *= 3;
        }
        int ans = 0;
        for (int mask1 = 0; mask1 < (1 << l); ++mask1) {
            for (int mask2 = 0; mask2 < (1 << r); ++mask2) {
                if (tol[mask1] != -1 && tor[mask2] != -1) {
                    int mask = (mask1 << r) | mask2;
                    int Q = tol[mask1] * MUL + tor[mask2];
                    //cout << mask << " " << Q << "  " << tol[mask1] << " " << tor[mask2] << ": " << cnt[mask] << " " << dp[Q] << endl;
                    ans += cnt[mask] * dp[Q];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}