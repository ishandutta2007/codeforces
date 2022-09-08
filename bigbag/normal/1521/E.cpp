/**
 *  created: 07/05/2021, 19:15:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_r = 700;

int t, m, k, ans[max_r][max_r];
vector<pair<int, int>> v;
vector<int> all;

void clr() {
    v.clear();
    all.clear();
}

bool good(int n) {
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < n; ++j) {
            if (ans[i][j] && ans[i + 1][j] && ans[i][j + 1] && ans[i + 1][j + 1]) {
                return false;
            }
            if (ans[i][j] && ans[i][j] == ans[i + 1][j + 1]) {
                return false;
            }
            if (ans[i][j + 1] && ans[i][j + 1] == ans[i + 1][j]) {
                return false;
            }
        }
    }
    return true;
}

bool check(int n) {
    if (n == 1) {
        if (all.size() == 1) {
            ans[0][0] = all[0];
            return true;
        }
        return false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = 0;
        }
    }
    int tp = 1;
    int row = 0, col = 1;
    for (int x : all) {
        if (row == -1) {
            return false;
        }
        ans[row][col] = x;
        col += 2;
        if (col >= n) {
            row += 2;
            col %= 2;
            if (row >= n) {
                ++tp;
                col = 0;
                if (tp == 4) {
                    row = -1;
                } else if (tp == 2) {
                    row = 0;
                } else {
                    row = 1;
                }
            }
        }
    }
    return good(n);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        clr();
        scanf("%d%d", &m, &k);
        for (int i = 1; i <= k; ++i) {
            int c;
            scanf("%d", &c);
            v.push_back({c, i});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (auto p : v) {
            for (int i = 0; i < p.first; ++i) {
                all.push_back(p.second);
            }
        }
        int max_ans = 1;
        while (m > max_ans * max_ans) {
            ++max_ans;
        }
        max_ans *= 2;
        //cout << "#" << max_ans << endl;
        /*for (int x = 1; x <= 10; ++x) {
            cout << x << ": " << check(x) << endl;
        }
        cout << check(2) << endl;
        return 0;*/
        int l = 0, r = max_ans + 5;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        check(r);
        printf("%d\n", r);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                printf("%d ", ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}