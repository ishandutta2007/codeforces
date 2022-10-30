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


long long ans;
int n;
vector<pair<int, int> > v[200005];
long long dp[200005][4];

void dfs(int x, int y, int z = 0) {
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y) continue;
        dfs(to, x, v[x][i].second);
        ans += dp[to][0] * dp[x][2];
        ans += dp[to][1] * (dp[x][2] + dp[x][3]);
        ans += dp[to][2] * (dp[x][0] + dp[x][1]);
        ans += dp[to][3] * dp[x][1];
        dp[x][0] += dp[to][0];
        dp[x][1] += dp[to][1];
        dp[x][2] += dp[to][2];
        dp[x][3] += dp[to][3];
    }
    ans += dp[x][0] + dp[x][1] + dp[x][2] + dp[x][3];
    if (z == 0) {
        dp[x][0] += dp[x][1];
        dp[x][1] = 0;
        dp[x][3] = 0;
        ++dp[x][0];
        ++dp[x][2];
    } else {
        dp[x][0] = 0;
        dp[x][3] += dp[x][2];
        dp[x][2] = 0;
        ++dp[x][1];
        ++dp[x][3];
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    dfs(1, 0);
    cout << ans << '\n';
}