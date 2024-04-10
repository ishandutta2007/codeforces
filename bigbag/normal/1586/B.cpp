/**
 *  created: 17/10/2021, 14:10:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        set<int> q;
        for (int i = 1; i <= n; ++i) {
            q.insert(i);
        }
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            if (q.count(b)) {
                q.erase(b);
            }
        }
        int root = *q.begin();
        for (int i = 1; i <= n; ++i) {
            if (i != root) {
                cout << i << " " << root << "\n";
            }
        }
    }
    return 0;
}