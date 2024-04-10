#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, bud, add, mul;
    cin >> n >> bud >> add >> mul;

    vector<int> b;
    vector<vector<i64>> a{{1}};

    i64 all = 1;

    for (int i = 0; i < n; ++i) {
        char c;
        int x;
        cin >> c >> x;

        if (c == '*') {
            if (x == 1) {
                continue;
            }
            all *= x;
            b.push_back(x);
            a.push_back({});
        } else {
            a.back().push_back(x);
        }
    }

    int l = a.size();
    vector<vector<i64>> suf(l);

    for (int i = 0; i < l; ++i) {
        sort(a[i].begin(), a[i].end());
		suf[i].resize(a[i].size() + 1);
        for (int j = a[i].size() - 1; j >= 0; --j) {
            suf[i][j] += suf[i][j + 1] + a[i][j];
        }
    }

    vector<int> last(l - 1, -1);

    for (int i = 0; i < l - 1; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (b[i] == b[j]) {
                last[i] = j;
                break;
            }
        }
    }

    i64 ans = 0;
    vector<bool> chosen(l - 1);

    function<void(int, int)> dfs = [&](int pos, int rest) {
        if (pos == l - 1) {
            i64 res = 0;
            vector<i64> coef(l, 1);

            for (int j = 0; j < l - 1; ++j) {
                if (chosen[j]) {
                    coef[l - 1] *= b[j];
                }
            }
            for (int j = l - 2; j >= 0; --j) {
                coef[j] = coef[j + 1];
                if (!chosen[j]) {
                    coef[j] *= b[j];
                }
            }
            for (int j = 0; j < l; ++j) {
                res += suf[j][0] * coef[j];
            }

            int k = rest / add;
            i64 L = 1, R = 1e18, val = 0;

            while (L <= R) {
                i64 mid = (L + R) >> 1;
                int cnt = 0;
                i64 tot = 0;

                for (int i = 0; i < l; ++i) {
                    i64 boost = all - coef[i];
                    if (boost == 0) {
                        continue;
                    }
                    i64 lim = (mid + boost - 1) / boost;
                    int pos = lower_bound(a[i].begin(), a[i].end(), lim) - a[i].begin();
                    if (pos < (int) a[i].size()) {
                        cnt += (int) a[i].size() - pos;
                        tot += boost * suf[i][pos];
                    }
                }    

                if (cnt <= k) {
                    val = tot + (k - cnt) * (mid - 1);
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }

            ans = max(ans, res + val);
            return;
        }

        dfs(pos + 1, rest);
        if (~last[pos] && !chosen[last[pos]]) {
            return;
        }
        if (rest >= mul) {
            chosen[pos] = true;
            dfs(pos + 1, rest - mul);
            chosen[pos] = false;
        }
    };
    dfs(0, bud);

    cout << ans << "\n";

    return 0;
}