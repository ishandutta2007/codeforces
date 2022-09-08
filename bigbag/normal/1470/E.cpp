/**
 *  created: 13/01/2021, 20:24:36
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 30033;
const int max_c = 5;
const long long inf = 1000111222000111222LL;

int t, n, c, q, a[max_n];
vector<int> order[max_n];
long long dp[max_n][max_c], A[max_c][max_n], B[max_n][max_c];
__int128 sumA[max_c][max_n];

__int128 get_sum(int c, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (!l) {
        return sumA[c][r];
    }
    return sumA[c][r] - sumA[c][l - 1];
}

int get_last(int pos, long long num, int c) {
    assert(dp[pos][c] >= num);
    int l = pos, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (dp[mid][c] + get_sum(c, pos, mid - 1) >= num) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

vector<pair<int, int>> solve(long long num, int c) {
    vector<pair<int, int>> res;
    int pos = 0;
    while (pos < n) {
        int last = get_last(pos, num, c);
        __int128 sum_pref = 0;
        if (pos) {
            sum_pref += sumA[c][pos - 1];
        }
        int first = lower_bound(sumA[c], sumA[c] + n, num + sum_pref) - sumA[c];
        //cout << "#" << pos << ": " << first << " " << last << ", c = " << c << ", num = " << num << "   " << A[c][first] << endl;
        first = min(first, last);
        if (first == n) {
            break;
        }
        num -= get_sum(c, pos, first - 1);
        //cout << "new num = " << num << endl;
        int oldc = c;
        for (int len : order[first]) {
            if (len > c) {
                continue;
            }
            if (num > dp[first + len + 1][c - len]) {
                //cout << "dec " << len << " " << dp[first + len + 1][c - len] << endl;
                num -= dp[first + len + 1][c - len];
            } else {
                assert(len);
                res.push_back({first, len});
                pos = first + len + 1;
                c -= len;
                break;
            }
        }
        assert(c != oldc);
    }
    return res;
}

int get_elem(const vector<pair<int, int>> &v, int pos) {
    for (auto p : v) {
        if (p.first <= pos && pos <= p.first + p.second) {
            pos -= p.first;
            pos = p.second - pos;
            pos += p.first;
            return a[pos];
        }
    }
    return a[pos];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &c, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        fill(dp[n], dp[n] + c + 1, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= c; ++j) {
                dp[i][j] = 0;
                for (int len = 0; i + len < n && len <= j; ++len) {
                    dp[i][j] += dp[i + len + 1][j - len];
                    dp[i][j] = min(dp[i][j], inf);
                }
            }
            order[i].clear();
            for (int len = 0; len <= c && i + len < n; ++len) {
                order[i].push_back(len);
            }
            sort(order[i].begin(), order[i].end(), [i](int x, int y) { return a[i + x] < a[i + y]; });
            for (int j = 0; j <= c; ++j) {
                B[j][i] = dp[i][j];
                A[j][i] = 0;
                for (int len : order[i]) {
                    if (len == 0) {
                        break;
                    }
                    if (len <= j) {
                        A[j][i] += dp[i + len + 1][j - len];
                        A[j][i] = min(A[j][i], inf);
                    }
                }
            }
        }
        for (int j = 0; j <= c; ++j) {
            sumA[j][0] = A[j][0];
            for (int i = 1; i < n; ++i) {
                sumA[j][i] = sumA[j][i - 1] + A[j][i];
            }
        }
        while (q--) {
            int pos;
            long long num;
            scanf("%d%lld", &pos, &num);
            --pos;
            if (dp[0][c] < num) {
                puts("-1");
            } else {
                vector<pair<int, int>> res = solve(num, c);
                int ans = get_elem(res, pos);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}