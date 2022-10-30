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



int n, sz;
int a[500005];
vector<int> v[4000005];
int ans[500005];
int used[4000005];
bool c;
vector<int> q;

void add(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        v[x].push_back(y);
        return;
    }
    int mid = (l + r) >> 1;
    add(l, mid, ll, rr, x + x, y);
    add(mid + 1, r, ll, rr, x + x + 1, y);
    return;
}

void dfs(int x, int y = 0) {
    used[x] = 1;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        if (used[to] == 0) dfs(to);
        else if (used[to] == 1) c = true;
    }
    used[x] = 2;
    q.push_back(x);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sz = 1;
        while (sz < n + 1) sz += sz;
        for (int i = 1; i <= sz + sz; ++i)
            used[i] = 0, v[i].clear();
        for (int i = 2; i <= sz + sz; ++i)
            v[i].push_back(i / 2);
        for (int i = 1; i <= n; ++i) if (a[i] != -1) {
            int x = a[i];
            v[sz + i - 1].push_back(sz + x - 1);
            if (x > i + 1) add(1, sz, i + 1, x - 1, 1, sz + i - 1);
        }
        c = false;
        q.clear();
        for (int i = 1; i <= sz + sz; ++i)
            if (used[i] == 0) dfs(i);
        if (c) {
            cout << "-1\n";
            continue;
        }
        reverse(q.begin(), q.end());
        int last = 0;
        for (int i = 0; i < (int)q.size(); ++i) {
            int x = q[i];
            if (x >= sz && x < sz + n) ans[x - sz + 1] = ++last;
        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}