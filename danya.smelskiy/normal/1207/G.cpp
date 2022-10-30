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
int gogo(int, int);
int get_link(int);


int nxt[400005][26];
int go[400005][26];
int link[400005];
int pred[400005];
int predc[400005];
int all;
int timer;
int tin[400005];
int tout[400005];
int n, m;
vector<int> vv[400005];
vector<pair<int, int> > v[400005], q[400005];
int f[400005];
int ans[400005];


int add(string s) {
    int last = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int x = s[i] - 'a';
        if (!nxt[last][x]) {
            nxt[last][x] = ++all;
            pred[all] = last;
            predc[all] = x;
            link[all] = -1;
            for (int i = 0; i < 26; ++i)
                go[all][i] = -1;
        }
        last = nxt[last][x];
    }
    return last;
}

int gogo(int x, int y) {
    if (go[x][y] != -1) return go[x][y];
    if (nxt[x][y]) return go[x][y] = nxt[x][y];
    if (x == 0) return go[x][y] = 0;
    return go[x][y] = gogo(get_link(x), y);
}

int get_link(int x) {
    if (link[x] != -1) return link[x];
    if (x == 0 || pred[x] == 0) return link[x] = 0;
    return link[x] = gogo(get_link(pred[x]), predc[x]);
}

void dfs1(int x) {
    tin[x] = ++timer;
    for (int i = 0; i < (int)vv[x].size(); ++i) {
        int to = vv[x][i];
        dfs1(to);
    }
    tout[x] = timer;
    return;
}

void update(int x, int y) {
    while (x <= timer) {
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

void dfs2(int x, int y) {
    for (int i = 0; i < (int)q[x].size(); ++i) {
        int xx = q[x][i].second;
        ans[q[x][i].first] = get(tout[xx]) - get(tin[xx] - 1);
    }
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        int c = v[x][i].second;
        int xx = gogo(y, c);
        update(tin[xx], 1);
        dfs2(to, xx);
        update(tin[xx], -1);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    link[0] = -1;
    for (int i = 0; i < 26; ++i)
        go[0][i] = -1;
    cin >> n;
    int tp;
    char c;
    int x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> tp;
        if (tp == 1) {
            cin >> c;
            x = c - 'a';
            v[0].push_back({i, x});
        } else {
            cin >> x;
            cin >> c;
            y = c - 'a';
            v[x].push_back({i, y});
        }
    }
    cin >> m;
    int xx;
    string s;
    for (int i = 1; i <= m; ++i) {
        cin >> xx;
        cin >> s;
        x = add(s);
        q[xx].push_back({i, x});
    }
    for (int i = 1; i <= all; ++i) {
        x = get_link(i);
        vv[x].push_back(i);
    }
    dfs1(0);
    dfs2(0, 0);
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';
    return 0;
}