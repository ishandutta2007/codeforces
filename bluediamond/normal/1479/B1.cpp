#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
const int INF = (int) 1e9;
int n, a[N], dp[N], b[N], Dif[N];

int sb(int l, int r) {
        return b[r] - b[l - 1];
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++)
                cin >> a[i];
        Dif[0] = -INF;
        set<pair<int, int>> st;
        for (int i = 1; i <= n; i++) {
                dp[i] = -INF;
                b[i] = b[i - 1] + (a[i] != a[i - 1]);
                Dif[i] = -INF;
        }
        for (int i = 0; i <= n; i++)
                st.insert({Dif[i], i});
        for (int i = 1; i <= n; i++) {
                dp[i] = sb(2, i) - b[i - 1];
                st.erase({Dif[a[i]], a[i]});
                auto it = st.end();
                it--;
                dp[i] = max(dp[i], it->first + 1);
                st.insert({Dif[a[i]], a[i]});
                dp[i] += b[i - 1];
                st.erase({Dif[a[i - 1]], a[i - 1]});
                Dif[a[i - 1]] = max(Dif[a[i - 1]], dp[i] - b[i]);
                st.insert({Dif[a[i - 1]], a[i - 1]});
        }
        int ret = -INF;
        for (int i = 1; i <= n; i++) {
                int cost = dp[i] + sb(i + 1, n);
                ret = max(ret, cost);
        }
        cout << min(ret + 1, n) << "\n";
}