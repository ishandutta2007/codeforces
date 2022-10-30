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
int a[205];
vector<int> v[205];
int dp[205][205];
int dp2[205];

void solve(int x, int y = 0) {
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) solve(to, x);
    }
    dp[x][0] = a[x];
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y) continue;
        for (int j = 0; j <= n; ++j)
            dp2[j] = dp[x][j];
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) if (j + k + 1 > m){
                dp2[min(j, k + 1)] = max(dp2[min(j, k + 1)], dp[x][j] + dp[to][k]);
            }
        }
        for (int j = 0; j <= n; ++j)
            dp[x][j] = dp2[j];
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve(1);
    int res = 0;
    for (int i = 0; i <= n; ++i)
        res = max(res, dp[1][i]);
    cout << res << '\n';
    return 0;
}