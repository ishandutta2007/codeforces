/**
 *  created: 25/07/2021, 17:55:18
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

int t, n, k, used[max_n], a[max_n], b[max_n];

bool is_inter(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    return l1 < l2 && l2 < r1 && r1 < r2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < k; ++i) {
            cin >> a[i] >> b[i];
            --a[i];
            --b[i];
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
            used[a[i]] = 1;
            used[b[i]] = 1;
        }
        vector<int> v;
        for (int i = 0; i < 2 * n; ++i) {
            if (!used[i]) {
                v.push_back(i);
            }
        }
        for (int i = 0; i < n - k; ++i) {
            a[k + i] = v[i];
            b[k + i] = v[i + n - k];
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cnt += is_inter(a[i], b[i], a[j], b[j]);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}