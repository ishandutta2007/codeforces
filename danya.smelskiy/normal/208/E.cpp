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



int n, m, timer;
int depth[100005];
vector<int> q[200005];
int tin[100005], tout[100005];
vector<int> v[100005];
vector<pair<int, int> > qq[100005];
int poc[100005];
int ans[100005];

void dfs(int x, int y) {
    depth[x] = depth[y] + 1;
    tin[x] = ++timer;
    q[depth[x]].push_back(timer);
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to, x);
    }
    tout[x] = timer;
    return;
}

int get(int x, int y) {
    int l = 0;
    int r = q[x].size() - 1;
    if (l > r) return 0;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (q[x][mid] <= y) l = mid;
        else r = mid - 1;
    }
    return (q[x][l] <= y ? l + 1 : 0);
}

void dfs2(int x, int y, int sz) {
    poc[sz] = x;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs2(to, x, sz + 1);
    }
    for (int i = 0; i < qq[x].size(); ++i) {
        int xx = qq[x][i].first;
        if (xx < sz) ans[qq[x][i].second] = get(depth[x], tout[poc[sz - xx]]) - get(depth[x], tin[poc[sz - xx]] - 1) - 1;
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> roots;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x == 0) roots.push_back(i);
        else v[x].push_back(i);
    }
    for (int i = 0; i < roots.size(); ++i)
        dfs(roots[i], 0);
    cin >> m;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        qq[x].push_back({y, i});
    }
    for (int i = 0; i < roots.size(); ++i)
        dfs2(roots[i], 0, 1);
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << " ";
    cout << '\n';
}