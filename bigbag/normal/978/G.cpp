#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, m, start[max_n], d[max_n], cnt[max_n], ans[max_n], need[max_n];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> start[i] >> d[i] >> cnt[i];
        ans[d[i]] = -i;
        need[d[i]] = cnt[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] < 0) {
            if (need[i]) {
                cout << -1 << endl;
                return 0;
            }
            ans[i] = m + 1;
            continue;
        }
        for (int j = i + 1; j <= n; ++j) {
            if (need[j] && i >= start[-ans[j]]) {
                ans[i] = -ans[j];
                --need[j];
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}