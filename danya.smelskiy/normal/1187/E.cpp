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

int x, y;
int n;
vector<int> v[200005];
long long cnt[200005];
long long dp[200005];
long long dp2[200005];
long long ans;

void solve(int x, int y = 0) {
    cnt[x] = 1;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y) continue;
        solve(to, x);
        dp[x] += dp[to] + cnt[to];
        cnt[x] += cnt[to];
    }
    return;
}

void solve2(int x, int y = 0) {
    long long cur = (y == 0 ? dp[x] : dp2[y] - cnt[x] + n - cnt[x]);
    ans = max(ans, cur);
    dp2[x] = cur;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y) continue;
        solve2(to, x);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve(1);
    solve2(1);
    cout << ans + n << '\n';
    return 0;
}