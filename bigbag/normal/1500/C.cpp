/**
 *  created: 13/03/2021, 12:34:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1555, inf = 1000111222;

int n, m, a[max_n][max_n], b[max_n][max_n], cnt[max_n];
bool del[max_n];
queue<int> q;

void del_row(int row) {
    del[row] = 1;
    for (int i = 0; i < m; ++i) {
        if (b[row][i] > b[row + 1][i]) {
            --cnt[i];
            if (!cnt[i]) {
                q.push(i);
            }
        }
    }
}

int cmp_col;
int p[max_n];

bool cmp(int r1, int r2) {
    return a[r1][cmp_col] < a[r2][cmp_col];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j + 1 < n; ++j) {
            cnt[i] += b[j][i] > b[j + 1][i];
        }
        if (!cnt[i]) {
            q.push(i);
            //cout << "###" << i << endl;
        }
    }
    while (!q.empty()) {
        int col = q.front();
        q.pop();
        ans.push_back(col);
        for (int i = 0; i + 1 < n; ++i) {
            if (!del[i] && b[i][col] < b[i + 1][col]) {
                del_row(i);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int col : ans) {
        cmp_col = col;
        stable_sort(p, p + n, cmp);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[p[i]][j] != b[i][j]) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", ans.size());
    for (int id : ans) {
        printf("%d ", id + 1);
    }
    puts("");
    return 0;
}