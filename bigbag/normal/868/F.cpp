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

const int max_n = 100111, inf = 1011111111;

int tm, last[max_n], cnt[max_n];

int n, k, a[max_n], opt[max_n];
int q1 = 0, q2 = 1;
long long dp[2][max_n];
vector<int> all[max_n];

int get_cnt(int x, int l, int r) {
    return upper_bound(all[x].begin(), all[x].end(), r) - lower_bound(all[x].begin(), all[x].end(), l);
}

void get_dp(int l, int r, int opt_l, int opt_r) {
    int mid = (l + r) / 2;
    int mn = opt_l, mx = min(opt_r, mid);
    long long best = dp[q1][mx - 1], sum = 0;
    opt[mid] = mx;
    ++tm;
    if (mx == mid) {
        last[a[mx]] = tm;
        cnt[a[mx]] = 1;
    }
    for (int i = mx - 1; i >= mn; --i) {
        int x = a[i];
        if (last[x] == tm) {
            sum += cnt[x];
        } else {
            if (mx == mid) {
                last[x] = tm;
                cnt[x] = 0;
            } else {
                last[x] = tm;
                cnt[x] = get_cnt(x, i + 1, mid);
            }
            sum += cnt[x];
        }
        ++cnt[x];
        if (best >= sum + dp[q1][i - 1]) {
            best = sum + dp[q1][i - 1];
            opt[mid] = i;
        }
    }
    if (l < mid) {
        get_dp(l, mid - 1, opt_l, opt[mid]);
        //get_dp(l, mid - 1, opt_l, opt_r);
    }
    if (mid < r) {
        //get_dp(mid + 1, r, opt_l, opt_r);
        get_dp(mid + 1, r, opt[mid], opt_r);
    }
}

long long sum;

void add(int x) {
    if (last[x] != tm) {
        cnt[x] = 0;
        last[x] = tm;
    }
    sum += cnt[x];
    ++cnt[x];
}

void err(int x) {
    --cnt[x];
    sum -= cnt[x];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        all[a[i]].push_back(i);
    }
    for (int i = 0; i < k; ++i) {
        if (i) {
            get_dp(i + 1, n, i, n);
        } else {
            for (int j = 1; j <= n; ++j) {
                opt[j] = 1;
            }
        }
        sum = 0;
        int l = i + 1, r = i + 1;
        ++tm;
        while (l <= n) {
            add(a[l]);
            while (r < opt[l]) {
                err(a[r]);
                ++r;
            }
            dp[q2][l] = dp[q1][opt[l] - 1] + sum;
            ++l;
        }
        swap(q1, q2);
        if (0) {
            for (int j = 1; j <= n; ++j) {
                if (j <= i) {
                    cout << "? ";
                } else {
                    cout << opt[j] << " ";
                }
            }
            cout << endl;
            for (int j = 1; j <= n; ++j) {
                if (j <= i) {
                    cout << "? ";
                } else {
                    cout << dp[q1][j] << " ";
                }
            }
            cout << endl;
            cout << endl;
        }
    }
    cout << dp[q1][n] << "\n";
    return 0;
}