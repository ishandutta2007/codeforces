#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long> > need(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'W') {
                need[i][j] = +1;
            } else {
                need[i][j] = -1;
            }
        }
    }

    vector<vector<long long> > cur(n, vector<long long>(m, 0));
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            long long diff = need[i][j] - cur[i][j];
            if (diff != 0) {
                ++ans;

                for (int ti = 0; ti <= i; ++ti) {
                    for (int tj = 0; tj <= j; ++tj) {
                        cur[ti][tj] += diff;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}