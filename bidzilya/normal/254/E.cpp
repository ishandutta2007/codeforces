#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v;
    cin >> n >> v;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const int kLim = 400;

    vector<vector<pair<int, int> > > f(kLim);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r, cf;
        cin >> l >> r >> cf;
        --l;
        --r;
        for (int j = l; j <= r; ++j) {
            f[j].push_back(make_pair(cf, i + 1));
        }
    }
    for (int i = 0; i < kLim; ++i) {
        sort(f[i].begin(), f[i].end());
    }

    vector<vector<int> > ans(kLim + 1, vector<int>(kLim + 1, -1));
    vector<vector<int> > pr_j(kLim + 1, vector<int>(kLim + 1)),
        pr_t(kLim + 1, vector<int>(kLim + 1));
    ans[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= kLim; ++j) {
            if (ans[i][j] != -1) {
                int rem = j + a[i];
                int sum = 0;
                for (int t = 0; t <= (int) f[i].size(); ++t) {
                    if (sum + v <= rem) {
                        int crem = min(rem - (sum + v), a[i]);
                        if (ans[i][j] + t > ans[i + 1][crem]) {
                            ans[i + 1][crem] = ans[i][j] + t;
                            pr_j[i + 1][crem] = j;
                            pr_t[i + 1][crem] = t;
                        }
                    }
                    if (t != (int) f[i].size()) {
                        sum += f[i][t].first;
                    }
                }
            }
        }
    }

    int ans_j;
    int ans_val = -1;
    for (int j = 0; j <= kLim; ++j) {
        if (ans[n][j] != -1) {
            if (ans[n][j] > ans_val) {
                ans_j = j;
                ans_val = ans[n][j];
            }
        }
    }

    cout << ans_val << endl;
    vector<vector<int> > ans_friends(n);
    for (int i = n, j = ans_j; i > 0; j = pr_j[i][j], --i) {
        for (int t = 0; t < pr_t[i][j]; ++t) {
            ans_friends[i - 1].push_back(f[i - 1][t].second);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans_friends[i].size() << " ";
        for (int j = 0; j < (int) ans_friends[i].size(); ++j) {
            cout << ans_friends[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}