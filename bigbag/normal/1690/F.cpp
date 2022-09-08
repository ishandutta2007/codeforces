/**
 *  created: 07/06/2022, 17:52:18
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

int t, n, p[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            --p[i];
        }
        vector<char> used(n);
        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                int pos = i;
                vector<char> v;
                while (!used[pos]) {
                    used[pos] = 1;
                    v.push_back(s[pos]);
                    pos = p[pos];
                }
                vector<char> start = v;
                for (int c = 1; ; ++c) {
                    rotate(v.begin(), v.begin() + 1, v.end());
                    if (v == start) {
                        ans /= __gcd(ans, 1LL * c);
                        ans *= c;
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}