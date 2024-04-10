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

const int max_n = 300333, inf = 1011111111;

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int get_cnt(int mask, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (get_bit(mask, i)) {
            for (int j = i + 1; j < n; ++j) {
                if (get_bit(mask, j) && (j + 1) % (i + 1) == 0) {
                    ++res;
                }
            }
        }
    }
    return res;
}

vector<int> get(int n) {
    vector<int> res;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int x = get_cnt(mask, n);
        if (x) {
            res.push_back(x);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

const int max_x = 200, max_q = 10000;

int cnt[max_n], sum[max_n], f[max_n];
int dp[max_q][max_x];

int get(const vector<int> &res) {
    int x = 0;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = i + 1; j < res.size(); ++j) {
            if (res[j] % res[i] == 0) {
                ++x;
            }
        }
    }
    return x;
}

vector<int> solve(int n, int k) {
    for (int i = 1; i <= n; ++i) {
        if (sum[i] >= k) {
            n = i;
            break;
        }
    }
    int l = n / 2 + 1, ones = 0;
    for (int i = l; i <= n; ++i) {
        ones += (cnt[i] == 1);
    }
    vector<int> res;
    for (int i = 1; i < l; ++i) {
        res.push_back(i);
    }
    k = sum[n] - k;
    //cout << l << " " << n << " " << k << "   " << ones << endl;
    if (ones >= k) {
        for (int i = l; i <= n; ++i) {
            if (cnt[i] == 1 && k) {
                --k;
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
    memset(dp, -1, sizeof(dp));
    memset(f, 0, sizeof(f));
    dp[l][0] = 0;
    for (int i = l; i <= n; ++i) {
        for (int cur = 0; cur <= k; ++cur) {
            if (dp[i][cur] != -1) {
                dp[i + 1][cur] = dp[i][cur];
                if (cur + cnt[i] <= k) {
                    dp[i + 1][cur + cnt[i]] = i;
                }
            }
        }
    }
    if (dp[n + 1][k] == -1) {
        exit(228);
    }
    int pos = n + 1;
    while (k) {
        int bad = dp[pos][k];
        f[bad] = 1;
        int nk = k - cnt[bad];
        pos = bad;
        k = nk;
    }
    for (int i = l; i <= n; ++i) {
        if (f[i] == 0) {
            res.push_back(i);
        }
    }
    return res;
}

void check(int n, int k) {
    vector<int> res = solve(n, k);
    if (0) {
        for (int x : res) {
            printf("%d ", x);
        }
        printf("\n");
    }
    if (get(res) != k) {
        cout << "FAIL" << endl;
        cout << get(res) << endl;
        cout << k << endl;
        exit(2);
    }
    //cout << "OK" << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i < max_n; ++i) {
        for (int j = 2 * i; j < max_n; j += i) {
            ++cnt[j];
        }
        sum[i] = sum[i - 1] + cnt[i];
    }
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > sum[n]) {
        printf("No\n");
        return 0;
    }
    vector<int> res = solve(n, k);
    printf("Yes\n%d\n", res.size());
    for (int x : res) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}