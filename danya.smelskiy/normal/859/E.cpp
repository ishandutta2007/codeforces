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
const int md = 1e9 + 7;

int n;
bool used_v[200005];
vector<int> v[200005];
int used[200005];
bool in_c[200005];
long long ans = 1;
vector<int> vv[200005];
long long dp[200005];

void dfs(int x) {
    used[x] = 1;
    for (auto to : v[x]) {
        if (used[to] == 0) {
            dfs(to);
            if (in_c[to]) in_c[x] = true;
        } else if (used[to] == 1) {
            in_c[x] = true;
            if (x == to) continue;
            ans <<= 1;
            if (ans >= md) ans -= md;
        }
    }
    used[x] = 2;
    return;
}

void solve(int x) {
    for (int i = 0; i < vv[x].size(); ++i) {
        int to = vv[x][i];
        solve(to);
        dp[x] += dp[to];
    }
    ++dp[x];
    dp[x] %= md;
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        used_v[x] = true;
        v[x].push_back(y);
        vv[y].push_back(x);
    }
    for (int i = 1; i <= n + n; ++i)
        if (!used[i]) dfs(i);
    for (int i = 1; i <= n + n; ++i) if (v[i].empty() && !vv[i].empty()) {
        solve(i);
        ans *= dp[i];
        ans %= md;
    }
    cout << ans << '\n';
    return 0;
}