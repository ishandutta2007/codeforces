#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int &a : A) cin >> a, --a;
        vector<int> fenw(N);
        auto modify = [&](int x, int y) {
            for (; x < N; x |= (x+1)) fenw[x] = max(fenw[x], y);
        };
        auto query = [&](int x) {
            int ans = 0;
            for (; x >= 0; x = (x & (x + 1)) - 1) ans = max(ans, fenw[x]);
            return ans;
        };
        int mx = -1;
        vector<int> dp(N);
        vector<int> st;
        for (int i = 0; i < N; ++i) {
            dp[i] = 1;
            if (A[i] <= mx) dp[i] = 2;
            else mx = A[i];
            dp[i] = max(dp[i], query(A[i]) + 1);
            while (st.size() && A[i] >= A[st.back()]) {
                modify(A[st.back()], dp[st.back()] + 1);
                st.pop_back();
            }
            modify(A[i], dp[i]);
            st.emplace_back(i);
        }
        mx = -1;
        int ans = 0;
        for (int i = N-1; i >= 0; --i) {
            ans = max(ans, dp[i] + (mx >= A[i]));
            mx = max(mx, A[i]);
        }
        cout << ans << '\n';
    }
}