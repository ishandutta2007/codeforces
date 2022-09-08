/**
 *  created: 16/12/2020, 18:12:57
**/

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> a;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt + (i - 1) / 2 < m) {
            a.push_back(i);
            cnt += (i - 1) / 2;
        } else {
            a.push_back(i + 2 * ((i - 1) / 2 - (m - cnt)));
            cnt = m;
            const int inf = 1000000000, step = 20000;
            int x = inf - step * n;
            while (a.size() < n) {
                a.push_back(x);
                x += step;
            }
            for (int x : a) {
                cout << x << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}