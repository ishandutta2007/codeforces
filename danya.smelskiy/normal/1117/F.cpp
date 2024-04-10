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
string s;
int dp[(1 << 18)][18];
int dp2[(1 << 18)];
int cnt[100];
int matr[100][100];
int last[100005][18];
bool used[100];
bool p[(1 << 18)];

inline void add_mask(int x, int y) {
    int cur = 0;
    for (int i = 0; i < m; ++i)
        if (used[i]) cur |= (1 << i);
//    cout << x << " "<< y << " "<< cur << '\n';
    dp[cur][x] |= (1 << y);
    dp[cur][y] |= (1 << x);
    return;
}

inline bool check(int x) {
    int y = (1 << m) - 1;
    y ^= x;
    for (int j = 0; j < m; ++j) if (!(x & (1 << j))) {
        if ((y & dp[x][j])) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; ++i)
        ++cnt[s[i] - 'a'];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matr[i][j];
        }
    }
    for (int i = 0; i < m; ++i)
        last[n + 1][i] = n + 1;
    int x;
    for (int i = n; i > 0; --i) {
        for (int j = 0; j < m; ++j) {
            last[i][j] = last[i + 1][j];
        }
        if (i < n) {
            x = s[i + 1] - 'a';
            last[i][x] = i + 1;
        }
        x = s[i] - 'a';
        for (int j = 0; j < m; ++j) {
            used[j] = false;
        }
        int r = i;
        while (r < n) {
            int nxt = 0, mn = 1e9;
            for (int j = 0; j < m; ++j) if (!used[j] && last[r][j] < mn) {
                nxt = j;
                mn = last[r][j];
            }
            if (mn > n) break;
            if (!matr[x][nxt]) {
                add_mask(x, nxt);
                break;
            }
            used[nxt] = true;
            r = last[r][nxt];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1 << m); ++j) if ((j & (1 << i))) {
            for (int k = 0; k < m; ++k)
                dp[j][k] |= dp[(j ^ (1 << i))][k];
        }
    }
    int cur;
    for (int i = 0; i < (1 << m); ++i)
        dp2[i] = n;
    int ans = n;
    p[0] = true;
    for (int i = 0; i < (1 << m); ++i) if (check(i) && p[i]) {
        ans = min(ans, dp2[i]);
        for (int j = 0; j < m; ++j)
            if (!(i & (1 << j))) {
                cur = (i | (1 << j));
                dp2[cur] = min(dp2[cur], dp2[i] - cnt[j]);
                p[cur] = true;
            }
    }
    cout << ans << '\n';
}