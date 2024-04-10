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

int n, x, y;
int clr[200005];
bool used[200005];
bool pr[200005];
int lc[200005];
vector<int> q[200005], vv[200005];

void init() {
    lc[1] = 1;
    for (int i = 2; i <= 2e5; ++i) if (!pr[i]) {
        lc[i] = i;
        for (int j = i + i; j <= 2e5; j += i) {
            pr[j] = true;
            lc[j] = i;
        }
    }
}

vector<int> get_vector(int x) {
    vector<int> res;
    int last = 0;
    while (x > 1) {
        if (lc[x] != last) res.push_back(lc[x]);
        last = lc[x];
        x /= last;
    }
    return res;
}

int ans = 0;

int dfs(int x) {
    int mx1 = 0, mx2 = 0;
    used[x] = true;
    for (int i = 0; i < vv[x].size(); ++i) {
        int to = vv[x][i];
        if (clr[to] == 0 || used[to]) continue;
        int cur = dfs(to);
        if (mx1 + cur + 1 > ans) ans = mx1 + cur + 1;
        if (cur >= mx1) {
            mx2 = mx1;
            mx1 = cur;
        } else if (cur > mx2) mx2 = cur;
    }
    return mx1 + 1;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        v = get_vector(x);
        for (int j = 0; j < v.size(); ++j)
            q[v[j]].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        vv[x].push_back(y);
        vv[y].push_back(x);
    }
    for (int i = 2; i <= 2e5; ++i) if (q[i].size() > 0) {
        v = q[i];
        for (int j = 0; j < v.size(); ++j)
            clr[v[j]] = 1;
        for (int j = 0; j < v.size(); ++j)
            if (!used[v[j]]) ans = max(ans, dfs(v[j]));
        for (int j = 0;j < v.size(); ++j) {
            clr[v[j]] = 0;
            used[v[j]] = false;
        }
    }
    cout << ans << '\n';
}