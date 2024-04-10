#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int M = (int) 1e9 + 7;

int rep(int x) {
        x %= M;
        if (x < 0)
                x += M;
        return x;
}

const int N = (int) 2e5 + 7;
int n;
int b[N];
int all[N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        int tt;
        cin >> tt;
        while (tt--) {
                cin >> n;
                for (int i = 1; i <= n; i++) {
                        cin >> b[i];
                        all[i] = 0;
                }
                map<int, int> dp;
                dp[0] = 1;
                all[0] = 1;
                int shift = 0;
                for (int i = 1; i <= n; i++) {
                        shift -= b[i];
                        all[i] = rep(all[i] - dp[b[i] + shift] + 2 * all[i - 1]);
                        dp[b[i] + shift] = all[i - 1];
                }
                cout << all[n] << "\n";
        }
}