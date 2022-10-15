#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 7;
const int B = 20;

int n, q, a[N];
int l[B];
int dp[N][B];

string solve(int l, int r) {
        for (int b = 0; b < B; b++) {
                if (a[r] & (1 << b) && dp[l][b] <= r) {
                        return "Shi";
                }
        }
        return "Fou";
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
                cin >> a[i];
        }

        for (int b = 0; b < B; b++) {
                l[b] = n + 1;
        }
        for (int i = n; i >= 1; i--) {

                for (int b = 0; b < B; b++) {
                        dp[i][b] = n + 1;
                }

                for (int b = 0; b < B; b++) {
                        if (l[b] <= n && (a[i] & (1 << b))) {
                                for (int b2 = 0; b2 < B; b2++) {
                                        dp[i][b2] = min(dp[i][b2], dp[l[b]][b2]);
                                }
                        }
                }

                for (int b = 0; b < B; b++) {
                        if ((a[i] & (1 << b))) {
                                dp[i][b] = i;
                        }
                }

                for (int b = 0; b < B; b++) {
                        if (a[i] & (1 << b)) {
                                l[b] = i;
                        }
                }
        }

        for (int tq = 1; tq <= q; tq++) {
                int l, r;
                cin >> l >> r;
                cout << solve(l, r) << "\n";
        }

        return 0;
}