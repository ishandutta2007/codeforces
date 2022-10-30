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
int a[100005], cnt[100005], nxt[100005];
vector<int> v[100005];
int p[100005];
int timer, tin[100005], tout[100005];
int ans[100005];
vector<pair<int, int> > q[100005];

void dfs(int x, int y) {
    cnt[x] = 1;
    int mx = 0;
    tin[x] = ++timer;
    p[timer] = a[x];
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) {
            dfs(to, x);
            cnt[x] += cnt[to];
            if (cnt[to] > mx) {
                mx = cnt[to];
                nxt[x] = to;
            }
        }
    }
    tout[x] = timer;
    return;
}

int f[100005];

void update(int x, int y) {
    while (x <= 100000) {
        f[x] += y;
        x = (x | (x + 1));
    }
    return;
}

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

void add(int x, int y = 1) {
    if (cnt[x]) update(cnt[x], -1);
    cnt[x] += y;
    if (cnt[x]) update(cnt[x], 1);
    return;
}

void dfs2(int x, int y, int z) {
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y && to != nxt[x]) dfs2(to, x, 0);
    }
    if (nxt[x]) {
        dfs2(nxt[x], x, 1);
        for (int i = tin[x]; i < tin[nxt[x]]; ++i)
            add(p[i]);
        for (int i = tout[nxt[x]] + 1; i <= tout[x]; ++i)
            add(p[i]);
    } else add(a[x], 1);
    for (int i = 0; i < q[x].size(); ++i) {
        ans[q[x][i].second] = get(100000) - get(q[x][i].first - 1);
    }
    if (!z) {
        for (int i = tin[x]; i <= tout[x]; ++i)
            add(p[i], -1);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        q[x].push_back({y, i});
    }
    dfs2(1, 0, 1);
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';
    return 0;
}