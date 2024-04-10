# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n, m;
int a[20][2005];
bool used[2005];
int dp[(1 << 14)];
int dp2[(1 << 14)];
int s[(1 << 14)];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int, int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                q.push_back({a[i][j], j});
            }
        }
        sort(q.begin(), q.end());
        for (int i = 0; i < m; ++i)
            used[i] = false;
        for (int i = (int)q.size() - 1, c = 0; i >= 0; --i) {
            int x = q[i].second;
            if (!used[x]) {
                ++c;
                used[x] = true;
                if (c == n) break;
            }
        }
        int c = 0;
        for (int j = 0; j < m; ++j) if (used[j]) {
            for (int i = 0; i < n; ++i)
                a[i][c] = a[i][j];
            ++c;
        }
        for (int i = 0; i < (1 << n); ++i)
            dp[i] = 0;
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < (1 << n); ++j)
                dp2[j] = dp[j];
            vector<int> v;
            for (int j = 0; j < n; ++j)
                v.push_back(a[j][i]);
            for (int it = 0; it < n; ++it) {
                for (int j = 0; j < (1 << n); ++j) {
                    s[j] = 0;
                    for (int k = 0; k < n; ++k)
                        if ((j & (1 << k))) s[j] += v[k];
                }
                for (int j = 0; j < (1 << n); ++j) {
                    for (int k = j; k >= 0; k = ((k - 1) & j)) {
                        dp2[j] = max(dp2[j], dp[k] + s[(j ^ k)]);
                        if (k == 0) break;
                    }
                }
                vector<int> vv;
                for (int j = 1; j < (int)v.size(); ++j)
                    vv.push_back(v[j]);
                vv.push_back(v[0]);
                v = vv;
            }
            for (int j = 0; j < (1 << n); ++j)
                dp[j] = dp2[j];
        }
        cout << dp[(1 << n) - 1] << '\n';
    }
    return 0;
}