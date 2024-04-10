#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1011, inf = 1011111111;

int n, cost[11], k[111], dp[max_n][max_n], pos[max_n], q[max_n][10], all[max_n], cntx[12], sum[12];
int last[max_n], is_finish[max_n], sum_finish[max_n];
pair<int, pair<int, int> > p[max_n];
char s[max_n];
string a, x[max_n];

string read() {
    scanf("%s", s);
    return s;
}

void upd(string &s, int len, char c) {
    string q = "";
    while (s.length() + q.length() < len) {
        q += c;
    }
    s = q + s;
}

int proc() {
    int mx = a.length();
    for (int i = 0; i < n; ++i) {
        mx = max(mx, (int) x[i].length());
    }
    ++mx;
    last[n] = mx - a.length();
    upd(a, mx, '0');
    for (int i = 0; i < n; ++i) {
        last[i] = mx - x[i].length();
        upd(x[i], mx, '0');
    }
    return mx;
}

int get(int l, int r, int x) {
    if (l > r) {
        return 0;
    }
    if (l == 0) {
        return q[r][x];
    }
    return q[r][x] - q[l - 1][x];
}

void get_sum() {
    for (int c = 10; c >= 0; --c) {
        sum[c] = sum[c + 1] + cntx[c];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    a = read();
    int alen = a.length();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        x[i] = read();
    }
    for (int i = 0; i <= 9; ++i) {
        scanf("%d", &cost[i]);
    }
    int len = proc();
    if (0) {
        cout << a << endl;
        for (int i = 0; i < n; ++i) {
            cout << x[i] << endl;
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[len - 1][0] = 0;
    for (int i = 0; i < n; ++i) {
        pos[i] = i;
        p[i] = make_pair(0, make_pair(0, i));
    }
    //cout << "$" << x[0][len - 1] << endl;
    for (int i = len - 1; i > 0; --i) {
        memset(cntx, 0, sizeof(cntx));
        for (int j = 0; j < n; ++j) {
            sum_finish[j] = is_finish[p[j].second.second];
            memset(q[j], 0, sizeof(q[j]));
            all[j] = x[p[j].second.second][i] - '0';
            ++cntx[all[j]];
            ++q[j][all[j]];
            //cout << "#" << all[j] << endl;
            if (j) {
                sum_finish[j] += sum_finish[j - 1];
                for (int k = 0; k < 10; ++k) {
                    q[j][k] += q[j - 1][k];
                }
            }
        }
        get_sum();
        for (int cnt = 0; cnt <= n; ++cnt) {
            if (dp[i][cnt] != -1) {
                //cout << i << " " << cnt << ": " << dp[i][cnt] << endl;
                char from = '0', to = '9';
                if (i + alen == len) {
                    from = '1';
                }
                if (a[i] != '?') {
                    from = to = a[i];
                }
                from -= '0';
                to -= '0';
                for (int c = from; c <= to; ++c) {
                    int res = 0;
                    for (int x = 0; x <= 9; ++x) {
                        /*if (i == 1 && get(0, n - cnt - 1, x)) {
                            cout << "$" << x << " " << get(0, n - cnt - 1, x) << "  c = " << c << "  cost = " << cost[(x + c) % 10] << endl;
                        }*/
                        if (x) {
                            res += get(0, n - cnt - 1, x) * cost[(x + c) % 10];
                        } else if (n - cnt - 1 >= 0) {
                            //cout << sum_finish[n - cnt - 1] << endl;
                            res += (get(0, n - cnt - 1, x) - sum_finish[n - cnt - 1]) * cost[(x + c) % 10];
                        }
                        res += get(n - cnt, n - 1, x) * cost[(x + c + 1) % 10];
                    }
                    int ncnt = sum[10 - c];
                    dp[i - 1][ncnt] = max(dp[i - 1][ncnt], dp[i][cnt] + res);
                }
            }
            --cntx[all[n - 1 - cnt]];
            ++cntx[all[n - 1 - cnt] + 1];
            get_sum();
        }


        for (int j = 0; j < n; ++j) {
            p[j] = make_pair(x[j][i], make_pair(pos[j], j));
        }
        sort(p, p + n);
        for (int j = 0; j < n; ++j) {
            pos[p[j].second.second] = j;
            if (last[j] >= i && last[n] >= i) {
                is_finish[j] = 1;
                //cout << "finish " << j << endl;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[0][i] != -1) {
            ans = max(ans, dp[0][i] + i * cost[1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}