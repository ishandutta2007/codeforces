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
int x, y, xx, yy;
pair<int, int> a[55];
pair<int, int> b[55];
vector<pair<int, int> > v1, v2;
vector<pair<int, long long> > v[200000];
vector<int> rv[200005];
int len1, len2;
int timer;
int used[200000];

vector<pair<int, int> > build(vector<pair<int, int> > v) {
    vector<pair<int, int> > w;
    for (int i = 0; i < (int)v.size(); ++i) {
        int x = v[i].first - 1;
        w.push_back({x, -1});
        x = v[i].second;
        w.push_back({x, 1});
    }
    sort(w.begin(), w.end());
    vector<pair<int, int> > res;
    int last = 0;
    for (int i = 0; i < (int)w.size(); ++i) {
        if (i && last) res.push_back({w[i - 1].first + 1, w[i].first});
        last += w[i].second;
    }
    return res;
}

void add(int x, int y, long long z) {
    v[x].push_back({y, z});
    v[y].push_back({x, 0});
    rv[x].push_back((int)v[y].size() - 1);
    rv[y].push_back((int)v[x].size() - 1);
    return;
}

long long dfs(int x, long long y) {
    if (used[x] == timer || y <= 0) return 0;
    used[x] = timer;
    if (x == 2) return y;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        long long z = dfs(to, min(v[x][i].second, y));
        if (z > 0) {
            v[x][i].second -= z;
            v[to][rv[x][i]].second += z;
            return z;
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
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> xx >> yy;
        a[i] = {x, y};
        b[i] = {xx, yy};
        v1.push_back({x, xx});
        v2.push_back({y, yy});
    }
    v1 = build(v1);
    v2 = build(v2);
    len1 = (int)v1.size();
    len2 = (int)v2.size();
    long long ans = 0;
    for (int i = 1; i <= len1; ++i) {
        int x = v1[i - 1].second - v1[i - 1].first + 1;
        add(1, 2 + i, x);
        ans += x;
    }
    for (int i = 1; i <= len2; ++i) {
        int y = v2[i - 1].second - v2[i - 1].first + 1;
        add(2 + len1 + i, 2, y);
        ans += y;
    }
    ans = 0;
    int all = 2 + len1 + len2;
    for (int i = 0; i < (int)v1.size(); ++i) {
        for (int j = 0; j < (int)v2.size(); ++j) {
            bool t = false;
            for (int k = 1; k <= m; ++k)
                if (a[k].first <= v1[i].first && v1[i].second <= b[k].first) {
                    if (a[k].second <= v2[j].first && v2[j].second <= b[k].second) {
                        t = true;
                        break;
                    }
                }
            if (t) {
                ++all;
                add(2 + i + 1, all, 1e15);
                add(all, 2 + len1 + j + 1, 1e15);
//                cout << ">" << all << " " << i + 1 << " " << j + 1 << '\n';
            }
        }
    }
    while (true) {
        ++timer;
        long long res = dfs(1, 1e15);
        if (res <= 0) break;
        ans += res;
    }
    cout << ans << '\n';
    return 0;
}