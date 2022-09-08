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

const int max_n = 202222;
const long long inf = 1011111111000000000LL;

int n, m, k, a[max_n], tp[max_n], cnt[5][max_n], last[5][max_n];
long long sum[5][max_n];
long long sum2[5][max_n];
vector<int> all[5], q;

void read(int q) {
    int cnt;
    scanf("%d", &cnt);
    while (cnt--) {
        int pos;
        scanf("%d", &pos);
        --pos;
        tp[pos] |= q;
    }
}

void proc() {
    for (int i = 0; i < n; ++i) {
        q.push_back(a[i]);
    }
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    map<int, int> m;
    for (int i = 0; i < q.size(); ++i) {
        m[q[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = m[a[i]];
    }
}

int get(int num, int pos, int x) {
    if (pos == -1) {
        return 0;
    }
    if (last[num][x] >= pos) {
        return pos + 1;
    }
    return last[num][x] + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    read(1);
    read(2);
    proc();
    for (int i = 0; i < n; ++i) {
        //cout << q[a[i]] << " " << tp[i] << endl;
        all[tp[i]].push_back(a[i]);
    }
    for (int i = 0; i < 4; ++i) {
        sort(all[i].begin(), all[i].end());
        memset(last[i], -1, sizeof(last[i]));
        for (int j = 0; j < all[i].size(); ++j) {
            ++cnt[i][all[i][j]];
            last[i][all[i][j]] = j;
            sum2[i][j] = q[all[i][j]];
            if (j) {
                sum2[i][j] += sum2[i][j - 1];
            }
        }
        for (int j = 0; j < q.size(); ++j) {
            sum[i][j] = 1LL * q[j] * cnt[i][j];
            if (j) {
                last[i][j] = max(last[i][j], last[i][j - 1]);
                cnt[i][j] += cnt[i][j - 1];
                sum[i][j] += sum[i][j - 1];
            }
        }
    }
    long long ans = inf, S = 0;
    for (int i = 0; i <= all[3].size(); ++i) {
        int mn = max(0, k - i);
        int have = 2 * mn + i;
        if (have > m || mn > (int) all[1].size() || mn > (int) all[2].size()) {
            if (i < all[3].size()) {
                S += q[all[3][i]];
                //cout << "#" << all[3][i] << endl;
            }
            continue;
        }
        int need = m - have;
        int l = -1, r = q.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int c = cnt[0][mid] + cnt[1][mid] + cnt[2][mid] - get(1, mn - 1, mid) - get(2, mn - 1, mid);
            //cout << "!!!" << mid << " " << c << "    " << get(1, mn - 1, mid) << " " << get(2, mn - 1, mid) << endl;
            if (c >= need) {
                r = mid;
            } else {
                l = mid;
            }
        }
        long long pl = 0, c = 0;
        if (mn) {
            pl = sum2[1][mn - 1] + sum2[2][mn - 1];
        }
        if (r) {
            pl += sum[0][r - 1];
            for (int tp = 1; tp < 3; ++tp) {
                pl += sum[tp][r - 1];
                int idx = min(last[tp][r - 1], mn - 1);
                if (idx >= 0) {
                    pl -= sum2[tp][idx];
                }
            }
            c = cnt[0][r - 1] + cnt[1][r - 1] + cnt[2][r - 1] - get(1, mn - 1, r - 1) - get(2, mn - 1, r - 1);
            //cout << "!!!" << r << " " << c << "    " << get(1, mn - 1, r - 1) << " " << get(2, mn - 1, r - 1) << endl;
            //cout << "@@@" << cnt[1][0] << endl;
        }
        pl += 1LL * (need - c) * q[r];
        ans = min(ans, pl + S);
        //cout << i << ": " << pl << " " << S << "  r = " << q[r] << "   c = " << c << endl;
        if (i < all[3].size()) {
            S += q[all[3][i]];
            //cout << "#" << all[3][i] << endl;
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    printf("%I64d\n", ans);
    return 0;
}