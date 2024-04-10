#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    vector<bool> already_good(n - 1, false);

    for (int j = 0; j < m; ++j) {
        bool need_del = false;

        for (int i = 0; i < n - 1; ++i) {
            if (already_good[i]) {
                continue;
            }
            if (a[i][j] > a[i + 1][j]) {
                need_del = true;
            }
        }

        if (need_del) {
            ++ans;
        } else {
            for (int i = 0; i < n - 1; ++i) {
                if (a[i][j] < a[i + 1][j]) {
                    already_good[i] = true;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}