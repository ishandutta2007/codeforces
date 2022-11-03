#include <bits/stdc++.h>
using namespace std;

int Accept(int l, int r, const vector<int>& t,
            vector<int>& a)
{
    int c = 0;
    for (int i = l; i <= r; ++i) {
        if (t[i] == -1) {
            ++c;
        } else {
            --a[t[i]];
        }
    }
    return c;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int m, k;
        cin >> m >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        int f = -1;
        vector<int> t(m - 1), r(m - 1);
        for (int i = 0; i + 1 < m; ++i) {
            cin >> t[i] >> r[i];
            --t[i];
            if (r[i]) {
                if (f == -1) {
                    f = i;
                }
            }
        }
        if (f == -1) {
            int c = Accept(0, m - 2, t, a);
            string ans;
            ans.resize(k);
            for (int i = 0; i < k; ++i) {
                if (a[i] <= c) {
                    ans[i] = 'Y';
                } else {
                    ans[i] = 'N';
                }
            }
            cout << ans << endl;
        } else {
            int c = Accept(0, f - 1, t, a);
            vector<bool> used(k, false);
            for (int i = f; i + 1 < m; ++i) {
                if (t[i] != -1) {
                    used[t[i]] = true;
                }
            }
            string ans;
            ans.resize(k);
            for (int i = 0; i < k; ++i) {
                ans[i] = 'N';
            }
            for (int i = 0; i < k; ++i) {
                if (!used[i] && a[i] <= c) {
                    ans[i] = 'Y';
                }
            }
            int mn = -1;
            for (int i = 0; i < k; ++i) {
                if (!used[i] && (mn == -1 || a[i] < a[mn])) {
                    mn = i;
                }
            }
            c -= a[mn];
            c += Accept(f, m - 2, t, a);
            for (int i = 0; i < k; ++i) {
                if (a[i] <= c) {
                    ans[i] = 'Y';
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}