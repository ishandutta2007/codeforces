#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 150000 + 7;
const int INF = (int) 1e9;
int n[4], a[4][N], dp[4][N];
vector<int> bad[4][N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        for (int i = 0; i < 4; i++)
                cin >> n[i];
        for (int i = 0; i < 4; i++)
                for (int j = 0; j < n[i]; j++)
                        cin >> a[i][j];
        for (int i = 1; i < 4; i++) {
                int cnt;
                cin >> cnt;
                for (int j = 0; j < cnt; j++) {
                        int x, y;
                        cin >> x >> y;
                        x--;
                        y--;
                        bad[i][y].push_back(x);
                }
        }
        multiset<int> st;
        for (int j = 0; j < n[0]; j++)
                dp[0][j] = a[0][j];
        for (int i = 1; i < 4; i++) {
                st.clear();
                st.insert(INF);
                for (int j = 0; j < n[i - 1]; j++)
                        st.insert(dp[i - 1][j]);
                for (int j = 0; j < n[i]; j++) {
                        for (auto &ind : bad[i][j])
                                st.erase(st.find(dp[i - 1][ind]));
                        dp[i][j] = *st.begin() + a[i][j];
                        for (auto &ind : bad[i][j])
                                st.insert(dp[i - 1][ind]);
                }
        }
        int ret = INF;
        for (int j = 0; j < n[3]; j++)
                ret = min(ret, dp[3][j]);
        if (ret == INF)
                ret = -1;
        cout << ret << "\n";
}