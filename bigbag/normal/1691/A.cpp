/**
 *  created: 31/05/2022, 17:35:28
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111111, inf = 1000111222;

int t, n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cnt(2);
        while (n--) {
            cin >> x;
            ++cnt[x % 2];
        }
        cout << min(cnt[0], cnt[1]) << "\n";
    }
    return 0;
}