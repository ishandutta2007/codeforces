/**
 *  created: 10/06/2022, 19:36:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, m, k;
string a[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> a[0] >> a[1];
        sort(a[0].rbegin(), a[0].rend());
        sort(a[1].rbegin(), a[1].rend());
        int id = 0;
        vector<int> c(2);
        string ans;
        while (!a[0].empty() && !a[1].empty()) {
            if (c[id] == k) {
                id ^= 1;
                c = {0, 0};
            } else if (a[0].back() < a[1].back()) {
                id = 0;
            } else {
                id = 1;
            }
            ans += a[id].back();
            a[id].pop_back();
            ++c[id];
            c[id ^ 1] = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}