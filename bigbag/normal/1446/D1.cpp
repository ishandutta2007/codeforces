#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;
const int max_x = 103;

int curt, val[2 * max_n], last[2 * max_n];

void set_val(int pos, int x) {
    pos += max_n;
    val[pos] = x;
    last[pos] = curt;
}

int get_val(int pos) {
    pos += max_n;
    if (last[pos] != curt) {
        return inf;
    }
    return val[pos];
}

int n, a[max_n], cnt[max_n][max_x];
vector<int> all[max_x];

int calc_pref() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        copy(cnt[i - 1], cnt[i - 1] + max_x, cnt[i]);
        ++cnt[i][a[i]];
        int mx = *max_element(cnt[i], cnt[i] + max_x);
        int cmx = 0;
        for (int j = 0; j < max_x; ++j) {
            cmx += cnt[i][j] == mx;
        }
        if (cmx >= 2) {
            res = i;
        }
    }
    return res;
}

int mnl[max_n];
int cnt2[max_x][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 200000;
        mt19937 gen;
        for (int i = 1; i <= n; ++i) {
            a[i] = gen() % 10 + 1;
        }
    } else {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
    }
    reverse(a + 1, a + n + 1);
    int ans = calc_pref();
    reverse(a + 1, a + n + 1);
    ans = max(ans, calc_pref());
    for (int i = 1; i <= n; ++i) {
        mnl[i] = inf;
        all[a[i]].push_back(i);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < max_x; ++j) {
            cnt2[j][i] = cnt[i][j];
        }
    }
    for (int x = 0; x < max_x; ++x) {
        for (int y = 0; y < max_x; ++y) {
            if (x == y) {
                continue;
            }
            ++curt;
            set_val(0, 0);
            for (int RR : all[x]) {
                const int r = RR - 1;
                //int l = get_val(cnt[r][x] - cnt[r][y]);
                int l = get_val(cnt2[x][r] - cnt2[y][r]);
                //if (r == 5 && x == 1 && y == 3) cout << l << " " << r << "   " << x<< " " << y << endl;
                mnl[r] = min(mnl[r], l);

                //int pos = cnt[RR][x] - cnt[RR][y];
                int pos = cnt2[x][RR] - cnt2[y][RR];
                if (last[pos + max_n] != curt) {
                    set_val(pos, RR);
                }
            }
        }
    }
    //printf("%d\n", ans);
    for (int r = 1; r < n; ++r) {
        int l = mnl[r];
        if (l < r) {
            int mx = 0, cmx = 0;
            for (int x = 0; x < max_x; ++x) {
                if (mx < cnt[r][x] - cnt[l][x]) {
                    mx = cnt[r][x] - cnt[l][x];
                    cmx = 0;
                }
                cmx += (mx == cnt[r][x] - cnt[l][x]);
            }
            if (cmx >= 2) {
                //cout << l << " " << r << endl;
                ans = max(ans, r - l);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}