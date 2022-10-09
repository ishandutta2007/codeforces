
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {

int n, k[2];
vi a[2];

vi dp[2], cnt[2];
ve<ii> st;

int main() {
    cin >> n;
    rep(i, 2) {
        cin >> k[i];
        a[i].resize(k[i]);
        rep(f, k[i])
            cin >> a[i][f];
    }
    rep(i, 2) {
        dp[i].resize(n, -2);
        cnt[i].resize(n, 0);
    }
    dp[0][0] = dp[1][0] = -1;
    st.push_back(ii(0, 0)); st.push_back(ii(1 ,0));
    while (st.size()) {
        bool p = st.back().xx;
        int u = st.back().yy;
        st.pop_back();
        for (auto i: a[!p]) {
            int v = (u - i + n) % n;
            if (dp[!p][v] != -2) continue;
            if (dp[p][u] == -1) {
                //!clog << !p << ' ' << v << ' ' << 1 << endl;
                dp[!p][v] = 1;
                st.push_back(ii(!p, v));
            } else {
                if (++cnt[!p][v] == k[!p]) {
                    //clog << !p << ' ' << v << ' ' << -1 << endl;
                    dp[!p][v] = -1;
                    st.push_back(ii(!p, v));
                }
            }
        }
    }
    rep(i, n) {
        if (dp[0][i] == -2) dp[0][i] = 0;
        if (dp[1][i] == -2) dp[1][i] = 0;
    }

    string msg[3] = {"Lose", "Loop", "Win"};
    rep(p, 2) {
        rep(i, n - 1) {
            cout << msg[dp[p][i + 1] + 1] << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Sol::main();
}