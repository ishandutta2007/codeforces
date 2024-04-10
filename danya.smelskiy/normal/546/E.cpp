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
int a[105];
int b[1005];
pair<int, int> e[205];
vector<int> v[505];
vector<int> r[505];
int ans[505][505];
int f[505][505];
int ff[505][505];

void add(int x, int y, int z) {
    f[x][y] = z;
    ff[x][y] = z;
    v[x].push_back(y);
    v[y].push_back(x);
    return;
}

bool used[505];

int dfs(int x, int y) {
    if (used[x] || y <= 0) return 0;
    used[x] = true;
    if (x == 2) return y;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        int res = dfs(to, min(f[x][to], y));
        if (res) {
            f[x][to] -= res;
            f[to][x] += res;
            return res;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    long long ss = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= m; ++i)
        cin >> e[i].first >> e[i].second;
    for (int i = 1; i <= n; ++i) {
        add(1, 2 + i, a[i]);
        add(2 + n + i, 2, b[i]);
        add(2 + i, 2 + n + i, 1e6);
    }
    for (int i = 1; i <= m; ++i) {
        int x = e[i].first;
        int y = e[i].second;
        add(2 + x, 2 + n + y, 1e9);
        add(2 + y, 2 + n + x, 1e9);
    }
    long long s = 0;
    for (int i = 1; i <= n; ++i)
        s += b[i], ss += a[i];
    long long res = 0;
    while (true) {
        memset(used, false, sizeof(used));
        long long cur = dfs(1, 1e9);
        if (!cur) break;
        res += cur;
    }
    if (res != s || s != ss) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << ff[2 + i][2 + n + j] - f[2 + i][2 + n + j] << " ";
        cout << '\n';
    }
    return 0;
}