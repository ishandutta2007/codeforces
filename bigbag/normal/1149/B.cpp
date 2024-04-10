#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, max_l = 255, inf = 1000111222;
const int max_c = 26;

int n, q, dp[max_l][max_l][max_l], nxt[max_n][max_c];
char s[max_n];
int l[3], r[3], a[3];
vector<int> v[3];

void upd(int a, int b, int c, int x) {
    dp[a][b][c] = min(dp[a][b][c], x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &q, s);
    for (int i = 0; i < max_c; ++i) {
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < max_c; ++j) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    for (int i = 0; i < max_l; ++i) {
        for (int j = 0; j < max_l; ++j) {
            for (int k = 0; k < max_l; ++k) {
                dp[i][j][k] = n;
            }
        }
    }
    dp[0][0][0] = -1;
    while (q--) {
        char tp, c;
        int num;
        scanf("\n%c%d", &tp, &num);
        --num;
        if (tp == '+') {
            scanf(" %c", &c);
            v[num].push_back(c - 'a');
            for (int i = 0; i < 3; ++i) {
                l[i] = 0;
                r[i] = v[i].size();
            }
            l[num] = v[num].size() - 1;
            for (int i = l[0]; i <= r[0]; ++i) {
                for (int j = l[1]; j <= r[1]; ++j) {
                    for (int k = l[2]; k <= r[2]; ++k) {
                        if (dp[i][j][k] == n) {
                            continue;
                        }
                        a[0] = i;
                        a[1] = j;
                        a[2] = k;
                        for (int p = 0; p < 3; ++p) {
                            if (a[p] == r[p]) {
                                continue;
                            }
                            ++a[p];
                            upd(a[0], a[1], a[2], nxt[dp[i][j][k] + 1][v[p][a[p] - 1]]);
                            --a[p];
                        }
                    }
                }
            }
        } else {
            v[num].pop_back();
            for (int i = 0; i < 3; ++i) {
                l[i] = 0;
                r[i] = v[i].size();
            }
            ++r[num];
            l[num] = r[num];
            for (int i = l[0]; i <= r[0]; ++i) {
                for (int j = l[1]; j <= r[1]; ++j) {
                    for (int k = l[2]; k <= r[2]; ++k) {
                        dp[i][j][k] = n;
                    }
                }
            }
        }
        //cout << dp[v[0].size()][v[1].size()][v[2].size()] << endl;
        if (dp[v[0].size()][v[1].size()][v[2].size()] < n) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}