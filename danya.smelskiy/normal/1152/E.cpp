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
pair<int, int> a[200005];
map<int, int> mt;
int all;
int x, y;
bool used[200005];
vector<pair<int, int> > v[200005];
int sz;
bool used2[200005];
int last[200005];
int ans[200005];
int outmt[200005];

void dfs(int x) {
    used[x] = true;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i].first;
        if (!used[to]) dfs(to);
    }
    return;
}

void dfs2(int x) {
    while (last[x] < (int)v[x].size()) {
        int y = last[x]++;
        int to = v[x][y].second;
        if (used2[to]) continue;
        used2[to] = true;
        dfs2(v[x][y].first);
    }
    ans[++sz] = x;
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 1; i < n; ++i) {
        cin >> y;
        x = a[i].first;
        a[i].second = y;
        if (x > y) {
            cout << "-1\n";
            return 0;
        }
        if (!mt[x]) mt[x] = ++all, outmt[all] = x;
        if (!mt[y]) mt[y] = ++all, outmt[all] = y;
        x = mt[x];
        y = mt[y];
        v[x].push_back(make_pair(y, i));
        v[y].push_back(make_pair(x, i));
    }
    if (all > n) {
        cout << "-1\n";
        return 0;
    }
    dfs(1);
    for (int i = 1; i <= all; ++i)
        if (!used[i]) {
            cout << "-1\n";
            return 0;
        }
    int xx1 = 0, xx2 = 0;
    int c = 0;
    for (int i = 1; i <= all; ++i) {
        int x = (int)v[i].size();
        if (x & 1) {
            if (xx1 == 0) xx1 = i;
            else if (xx2 == 0) xx2 = i;
            else {
                cout << "-1\n";
                return 0;
            }
        }
    }
    if (xx1) {
        v[xx1].push_back(make_pair(xx2, n));
        v[xx2].push_back(make_pair(xx1, n));
    }
    dfs2(1);
    if (xx1) {
        for (int i = 1; i < sz; ++i)
            if ((ans[i] == xx1 && ans[i + 1] == xx2) || (ans[i] == xx2 && ans[i + 1] == xx1)) {
                for (int j = i + 1; j <= sz; ++j)
                    cout << outmt[ans[j]] << " ";
                for (int j = 2; j <= i; ++j)
                    cout << outmt[ans[j]] << " ";
                cout << '\n';
                return 0;
            }
    }
    for (int i = 1; i <= n; ++i)
        cout << outmt[ans[i]] << " ";
    cout << '\n';
    return 0;
}