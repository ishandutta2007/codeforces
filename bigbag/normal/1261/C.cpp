#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n, m;
vector<vector<int>> sum, ans;
string s[max_n];

void proc(vector<vector<int>> &sum) {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j];
        }
    }
}

int get_sum(const vector<vector<int>> &sum, int lx, int rx, int ly, int ry) {
    int res = sum[rx][ry];
    if (lx - 1 >= 0) {
        res -= sum[lx - 1][ry];
    }
    if (ly - 1 >= 0) {
        res -= sum[rx][ly - 1];
    }
    if (lx - 1 >= 0 && ly - 1 >= 0) {
        res += sum[lx - 1][ly - 1];
    }
    return res;
}

bool check(int t, bool ok) {
    int tot = (2 * t + 1) * (2 * t + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = 0;
            if (i - t >= 0 && i + t < n && j - t >= 0 && j + t < m && get_sum(sum, i - t, i + t, j - t, j + t) == tot) {
                ans[i][j] = 1;
            }
        }
    }
    if (ok) {
        return true;
    }
    proc(ans);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'X') {
                if (get_sum(ans, max(0, i - t), min(n - 1, i + t), max(0, j - t), min(m - 1, j + t)) == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    ans.resize(n, vector<int> (m, 0));
    sum.resize(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) {
        s[i] = read();
        for (int j = 0; j < m; ++j) {
            sum[i][j] = s[i][j] == 'X';
        }
    }
    proc(sum);
    int l = 0, r = 5111;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid, false)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    check(l, true);
    printf("%d\n", l);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j]) {
                printf("X");
            } else {
                printf(".");
            }
        }
        puts("");
    }
    return 0;
}