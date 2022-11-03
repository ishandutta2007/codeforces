#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

inline int GetAmountOfBits(int mask, int n)
{
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += GetBit(mask, i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > is(n, vector<int>(n, 0));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        is[x][y] = c;
    }
    vector<vector<long long> > dp(1 << n, vector<long long>(n, -1));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = a[i];
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int v = 0; v < n; ++v) {
            if (dp[mask][v] != -1 && GetBit(mask, v)) {
                for (int u = 0; u < n; ++u) {
                    if (!GetBit(mask, u)) {
                        int new_mask = mask + (1 << u);
                        dp[new_mask][u] = max(dp[new_mask][u], dp[mask][v] + is[v][u] + a[u]);
                    }
                }
            }
        }
    }
    
    long long ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int v = 0; v < n; ++v) {
            if (GetAmountOfBits(mask, n) == m) {
                ans = max(ans, dp[mask][v]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}