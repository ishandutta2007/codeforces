#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
        a += b;
        if (a >= M)
                return a - M;
        if (a < 0)
                return a + M;
        return a;
}

int mul(int a, int b) {
        return a * (ll) b % M;
}

int n, m, k;
int dp[N], dp2[N], pre[N];

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n >> m >> k;
        for (int i = 1; i < N; i++) {
                dp[i] = 1;
                pre[i] = i;
        }
        int l = max(n, m);
        /**for (int s = 1; s <= k; s++) {
                for (int i = 1; i <= l; i++) {
                        for (int j = 1; j <= i - 2; j++) {
                                dp2[i] = add(dp2[i], mul(i - j - 1, dp[j]));
                        }
                }
                for (int i = 1; i <= l; i++) {
                        dp[i] = dp2[i];
                        dp2[i] = 0;
                }
        }**/
        for (int s = 1; s <= k; s++) {
                int cur = 0;
                for (int i = 1; i <= l; i++) {
                        if (i >= 2)
                                cur = add(cur, pre[i - 2]);
                        dp2[i] = cur;
                }
                for (int i = 1; i <= l; i++) {
                        dp[i] = dp2[i];
                        pre[i] = add(pre[i - 1], dp[i]);
                }
        }
        int sol = mul(dp[n], dp[m]);
        cout << sol << "\n";
        return 0;
}