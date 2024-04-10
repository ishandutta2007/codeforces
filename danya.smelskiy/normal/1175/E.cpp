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
int dp[20][500005];
vector<int> v[500005], q[500005];
int x, y;
bool used[500005];

void dfs(int x, int y = 0) {
    used[x] = true;
    dp[0][x] = y;
    for (int i = 1; i < 20; ++i)
        dp[i][x] = dp[i - 1][dp[i - 1][x]];
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to, x);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        ++x;
        ++y;
        q[x].push_back(y);
    }
    int last = -1;
    for (int i = 1; i <= 500001; ++i) {
        for (int j = 0; j < (int)q[i].size(); ++j) {
            if (q[i][j] > last) last = q[i][j];
        }
        if (last > i) v[last].push_back(i);
    }
    for (int i = 500001; i >= 1; --i) if (!used[i]) dfs(i);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        ++x; ++y;
        int res = 0;
        for (int j = 19; j >= 0; --j) if (dp[j][x] && dp[j][x] < y) {
            res += (1 << j);
            x = dp[j][x];
        }
//        cout << ">" << x << " " << y << '\n';
        if (x < y && dp[0][x]) {
            ++res;
            x = dp[0][x];
        }
        if (x >= y) cout << res << '\n';
        else cout << "-1\n";
    }
    return 0;
}