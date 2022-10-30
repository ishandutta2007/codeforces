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


int n;
int a[205];
vector<int> v[505];
int f[505][505];
int num[505];
int all;
bool q[505];

vector<int> vv[505], qq;

bool used[505];


void dfs(int x) {
    used[x] = true;
    qq.push_back(x);
    for (int i = 0; i < (int)vv[x].size(); ++i) {
        int to = vv[x][i];
        if (!used[to]) dfs(to);
    }
    return;
}

inline bool check(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

void add(int x, int y, int z) {
    v[x].push_back(y);
    f[x][y] = z;
    v[y].push_back(x);
    return;
}

int dfs(int x, int y) {
    if (used[x] || y <= 0) return 0;
    used[x] = true;
    if (x == 2) return y;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        int cur = dfs(to, min(y, f[x][to]));
        if (cur > 0) {
            f[x][to] -= cur;
            f[to][x] += cur;
            return cur;
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
    cin >> n;
    int c1 = 0, c2 = 0;
    int all = 2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        num[i] = ++all;
        if (a[i] & 1) {
            q[i] = false;
            ++c1;
        } else {
            q[i] = true;
            ++c2;
        }
    }
    if (c1 != c2) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (!q[i]) {
            add(1, num[i], 2);
        } else {
            add(num[i], 2, 2);
        }
    }
    for (int i = 1; i <= n; ++i) if (!q[i]) {
        for (int j = 1; j <= n; ++j) if (check(a[i] + a[j])) {
            add(num[i], num[j], 1);
        }
    }
    int res = 0;
    while (true) {
        memset(used, false, sizeof(used));
        int cur = dfs(1, 1e9);
        if (cur == 0) break;
        res += cur;
    }
    if (res != n) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) if (!q[i]) {
        int x = num[i];
        for (int j = 0; j < (int)v[x].size(); ++j) {
            int to = v[x][j];
            if (to <= 2) continue;
            if (f[x][to] == 1) continue;
            vv[i].push_back(to - 2);
            vv[to - 2].push_back(i);
        }
    }
    vector<vector<int> > ans;
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; ++i)
        if (used[i] == false) {
            qq.clear();
            dfs(i);
            ans.push_back(qq);
        }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << (int)ans[i].size() << " ";
        for (int j = 0; j < (int)ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
}