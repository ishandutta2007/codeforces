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
const long long md = 1e9 + 7;

int n, m;
int x, y, z;
vector<int> v[100005];
bool used[100005];
int all;

void dfs(int x) {
    used[x] = true;
    ++all;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        if (!used[to]) dfs(to);
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
        cin >> x >> y >> z;
        if (!z) {
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    long long ans = 1;
    for (int i = 1; i <= m; ++i) {
        ans *= n;
        ans %= md;
    }
    for (int i = 1; i <= n; ++i) if (!used[i]) {
        all = 0;
        dfs(i);
        long long cur = 1;
        for (int i = 1; i <= m; ++i) {
            cur *= all;
            cur %= md;
        }
        ans -= cur;
        if (ans < 0) ans += md;
    }
    cout << ans << '\n';
    return 0;
}