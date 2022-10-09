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
        int n ;cin >> n;
        vector<llong> a(n);
        rep(i, n) cin >> a[i];

        llong sum = 0;
        llong xor_sum = 0;
        rep(i, n) {
            sum += a[i];
            xor_sum ^= a[i];
        }

        static short dp[63][10][2];
        memset(dp, -1, sizeof(dp));

        llong ans[3] = {0, 0, 0};
        function<short(llong , int, int)> cal_dp = [&](llong i, int carry, bool prev_xor_dig = 0) -> short {
            int cur_sum_dig = (sum >> i) & 1ll;
            if (i == 62) return carry == 0 and prev_xor_dig == 0;
            if (dp[i][carry][prev_xor_dig] != -1) return dp[i][carry][prev_xor_dig];

            dp[i][carry][prev_xor_dig] = 0;
            rep(add, 4) {
                int cur_sum = cur_sum_dig + add + carry;
                if ((cur_sum & 1) != prev_xor_dig) continue;
                int new_carry = cur_sum >> 1;
                bool cur_xor_dig = ((xor_sum >> i) ^ add) & 1ll;
                if (!cal_dp(i + 1, new_carry, cur_xor_dig)) continue;
                dp[i][carry][prev_xor_dig] = 1;
                rep(f, add) ans[f] ^= 1ll << i;
                return 1;
            }
            return 0;
        };
        bool has = cal_dp(0, 0, 0);
        assert(has);
        cout << "3\n";
        rep(i, 3) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}