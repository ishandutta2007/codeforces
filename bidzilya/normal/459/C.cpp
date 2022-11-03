#include <bits/stdc++.h>
using namespace std;

bool Solve(int n, int k, int d, vector<vector<int> >& ans)
{
    if (ans.size() == d) {
        return false;
    }
    if (n <= k) {
        for (int i = 0; i < n; ++i) {
            ans[d].push_back(i + 1);
        }
        for (int cd = d + 1; cd < (int) ans.size(); ++cd) {
            for (int i = 0; i < n; ++i) {
                ans[cd].push_back(1);
            }
        }
        return true;
    }
    int q = n / k;
    int r = n % k;
    for (int i = 0; i < k; ++i) {
        int ci = q + (r >= i + 1);
        for (int j = 0; j < ci; ++j) {
            ans[d].push_back(i + 1);
        }
        if (!Solve(ci, k, d + 1, ans)) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k, d;
    cin >> n >> k >> d;

    vector<vector<int> > ans(d);

    if (!Solve(n, k, 0, ans)) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}