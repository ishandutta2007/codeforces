/**
 *  created: 05/09/2021, 17:46:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 15, inf = 1000111222;

int t;
string s;

int get_bit(int mask, int pos) {
    if (pos < 0) {
        return 0;
    }
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        reverse(s.begin(), s.end());
        long long ans = 0;
        for (int mask = 0; mask < (1 << max<int>(0, s.size() - 2)); ++mask) {
            long long ways = 1;
            for (int i = 0; i < s.size(); ++i) {
                const int add = get_bit(mask, i - 2);
                const int need = get_bit(mask, i) * 10 + s[i] - '0' - add;
                const int l = max(0, need - 9), r = min(9, need);
                ways *= max(0, r - l + 1);
            }
            ans += ways;
        }
        ans -= 2;
        cout << ans << "\n";
    }
    return 0;
}