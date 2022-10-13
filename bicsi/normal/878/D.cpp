#include <bits/stdc++.h>

using namespace std;

vector<bitset<1 << 12>> DP;
int Char[12][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, q; cin >> n >> k >> q;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Char[i][j]; 
        }
    }

    for (int i = 0; i < k; ++i) {
        DP.push_back(bitset<1 << 12>());
        for (int c = 0; c < (1 << k); ++c) {
            DP[i][c] = !!(c & (1 << i));
        }
    }

    int creats = k;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x; --y;

        if (t == 1) {
            DP.push_back(DP[x] | DP[y]);
        }
        if (t == 2) {
            DP.push_back(DP[x] & DP[y]);
        }
        if (t <= 2) ++creats;

        if (t == 3) {
            int ans = 0;
            for (int i = 0; i < k; ++i) {
                int now = Char[i][y];
                int conf = 0;
                for (int i = 0; i < k; ++i) {
                    if (Char[i][y] >= now)
                        conf |= (1 << i);
                }
                conf = DP[x][conf];
                if (conf) ans = max(ans, now);
            } 
            cout << ans << '\n';
        }
    }


    return 0;
}