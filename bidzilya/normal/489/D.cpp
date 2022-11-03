#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > gout(n), gin(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        gout[v1].push_back(v2);
        gin[v2].push_back(v1);
    }

    vector<vector<int> > cnt(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) gin[i].size(); ++j) {
            for (int k = j + 1; k < (int) gin[i].size(); ++k) {
                int v1 = gin[i][j];
                int v2 = gin[i][k];

                ++cnt[v1][v2];
                ++cnt[v2][v1];
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) gout[i].size(); ++j) {
            for (int k = j + 1; k < (int) gout[i].size(); ++k) {
                int v1 = gout[i][j];
                int v2 = gout[i][k];

                ans += cnt[v1][v2];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cnt[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) gin[i].size(); ++j) {
            for (int k = j + 1; k < (int) gin[i].size(); ++k) {
                int v1 = gin[i][j];
                int v2 = gin[i][k];

                ++cnt[v1][v2];
                ++cnt[v2][v1];
            }
        }
        for (int j = 0; j < (int) gout[i].size(); ++j) {
            for (int k = j + 1; k < (int) gout[i].size(); ++k) {
                int v1 = gout[i][j];
                int v2 = gout[i][k];

                if (cnt[v1][v2]) {
                    --ans;
                }
            }
        }
        for (int j = 0; j < (int) gin[i].size(); ++j) {
            for (int k = j + 1; k < (int) gin[i].size(); ++k) {
                int v1 = gin[i][j];
                int v2 = gin[i][k];

                --cnt[v1][v2];
                --cnt[v2][v1];
            }
        }
    }

    cout << ans << endl;

    return 0;
}