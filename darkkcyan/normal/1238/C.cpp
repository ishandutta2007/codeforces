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
        llong h, n; cin >> h >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        rep1(i, n - 1) {
            bool is_next_to = a[i - 1] - 1 == a[i];
            dp[i] = min(dp[i], dp[i - 1] + 1);
            if (i > 1 and is_next_to)
                dp[i] = min(dp[i], dp[i - 2]);
            // clog << i << ' ' << is_next_to << ' ' << dp[i] << endl;
        }
        int ans = dp.back();
        if (a.back() == 1 and h > 1)  {
            ans = min(dp[n - 2], ans);
            // clog << dp[n - 2] << endl;
        }
        // clog << endl;
        cout << ans << '\n';
    }

    return 0;
}