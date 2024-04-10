#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        string target;
        rep(i, k - 1) target += "()";
        int n_left = n - 2 * (k - 1);
        target += string( n_left / 2, '(') + string(n_left / 2, ')');
        vector<pair<int, int>> ans;
        rep(i, n) {
            if (target[i] == s[i]) continue;
            for (int f = i + 1; f < n; ++f) if (s[f] == target[i]) {
                ans.emplace_back(i, f);
                reverse(s.begin() + i, s.begin() + f + 1);
                break;
            }
        }
        cout << len(ans) << '\n';
        for (auto [l, r]: ans) cout << l + 1 << ' ' << r + 1 << '\n';
    }

    return 0;
}