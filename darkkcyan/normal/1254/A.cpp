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
    string alphabet;
    for (char c = 'a'; c <= 'z'; ++c) alphabet += c;
    for (char c = 'A'; c <= 'Z'; ++c) alphabet += c;
    for (char c = '0'; c <= '9'; ++c) alphabet += c;

    int ntest; cin >> ntest;
    while (ntest--) {
        int n, m, k; cin >> n >> m >> k;
        vector<string> s(n);
        rep(i, n) cin >> s[i];

        int cnt_r = 0;
        rep(i, n) rep(f, m)
            cnt_r += s[i][f] == 'R';

        int min_rice = cnt_r / k;
        int max_rice = min_rice + 1;
        int cnt_min = k - cnt_r % k;
        vector<int> distribution(cnt_min, min_rice);
        rep(i, cnt_r - k) distribution.push_back(max_rice);

        vector<string> ans = s;

        for (int i = 1; i < n; i += 2) reverse(s[i].begin(), s[i].end());
        int cell = 0;
        rep(chick, k) {
            for (; distribution[chick]; ++cell) {
                int r = cell / m, c = cell % m;
                ans[r][c] = alphabet[chick];
                distribution[chick] -= s[r][c] == 'R';
            }
        }

        for (; cell < n * m; ++cell) {
            ans[cell / m][cell % m] = alphabet[k - 1];
        }

        rep(i, n) {
            if (i & 1) reverse(ans[i].begin(), ans[i].end());
            cout << ans[i] << '\n';
        }

        
    }

    return 0;
}