/**
 *  created: 23/02/2021, 11:54:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 250555, inf = 1000111222;

int n, m, cnt[max_n], real_cnt[max_n];
bool ok_col[max_n];
vector<int> a[max_n], ids;

void write(int col1, int col2, int val1, int val2) {
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (i == col1) {
            ans.push_back(val1);
        } else if (i == col2) {
            ans.push_back(val2);
        } else {
            ans.push_back(a[0][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            cnt += a[i][j] != ans[j];
        }
        assert(cnt <= 2);
    }
    puts("Yes");
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
    exit(0);
}

void solve(int col1, int col2) {
    for (int i = 1; i < n; ++i) {
        real_cnt[i] = cnt[i];
        real_cnt[i] -= a[i][col1] != a[0][col1];
        real_cnt[i] -= a[i][col2] != a[0][col2];
        if (real_cnt[i] > 2) {
            return;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (real_cnt[i] == 2) {
            bool ok = 1;
            for (int j = 1; j < n; ++j) {
                int c = real_cnt[j];
                c += a[j][col1] != a[i][col1];
                c += a[j][col2] != a[i][col2];
                ok &= c <= 2;
            }
            if (ok) {
                write(col1, col2, a[i][col1], a[i][col2]);
            }
            return;
        }
    }
    int row1 = -1;
    for (int i = 1; i < n; ++i) {
        if (real_cnt[i] == 1) {
            row1 = i;
            break;
        }
    }
    if (row1 == -1) {
        write(col1, col2, 1, 1);
        return;
    }
    for (int it = 0; it < 2; ++it) {
        bool ok = 1;
        int need_val = -1;
        for (int i = 1; i < n; ++i) {
            int c = real_cnt[i];
            c += a[i][col1] != a[row1][col1];
            if (c > 2) {
                ok = 0;
                break;
            }
            if (c == 2) {
                if (need_val != -1 && need_val != a[i][col2]) {
                    ok = 0;
                    break;
                }
                need_val = a[i][col2];
            }
        }
        if (ok) {
            if (need_val == -1) {
                need_val = 1;
            }
            write(col1, col2, a[row1][col1], need_val);
            return;
        }
        swap(col1, col2);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int &x : a[i]) {
            scanf("%d", &x);
        }
    }
    int cnt_ok = 0;
    for (int i = 0; i < m; ++i) {
        ok_col[i] = 1;
        for (int j = 0; j < n; ++j) {
            ok_col[i] &= a[j][i] == a[0][i];
        }
        cnt_ok += ok_col[i];
    }
    if (m - cnt_ok > 2 * n) {
        puts("No");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        if (!ok_col[i]) {
            ids.push_back(i);
        }
    }
    if (ids.size() <= 2) {
        write(-1, -1, -1, -1);
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int col : ids) {
            cnt[i] += a[i][col] != a[0][col];
        }
    }
    for (int i = 0; i < ids.size(); ++i) {
        for (int j = i + 1; j < ids.size(); ++j) {
            solve(ids[i], ids[j]);
        }
    }
    puts("No");
    return 0;
}