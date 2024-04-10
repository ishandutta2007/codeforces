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
int timer;
vector<int> v[400005];
int tin[400005], tout[400005];
long long t[2000005], q[2000005];
bool ob[2000005];
long long a[400005];
int x, y, sz;

void dfs(int x, int y) {
    tin[x] = ++timer;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) dfs(to, x);
    }
    tout[x] = timer;
}

void push(int x) {
    t[x + x] = t[x + x + 1] = q[x + x + 1] = q[x + x] = q[x];
    ob[x] = false;
    ob[x + x] = ob[x + x + 1] = true;
    return;
}

void update(int l, int r, int ll, int rr, int x, long long y) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        t[x] = y;
        q[x] = y;
        ob[x] = true;
        return;
    }
    int mid = (l + r) >> 1;
    if (ob[x]) push(x);
    update(l, mid, ll, rr, x + x, y);
    update(mid + 1, r, ll, rr, x + x + 1, y);
    t[x] = (t[x + x] | t[x + x + 1]);
    return;
}

long long get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    if (ob[x]) push(x);
    return (get(l, mid, ll, rr, x + x) | (get(mid + 1, r, ll, rr, x + x + 1)));
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= n; ++i) {
        update(1, sz, tin[i], tin[i], 1, (1ll << a[i]));
    }
    int ans;
    long long res;
    
    while (m--) {
        int tp, x, y;
        cin >> tp >> x;
        if (tp == 1) {
            cin >> y;
            update(1, sz, tin[x], tout[x], 1, (1ll << y));
        } else {
            res = get(1, sz, tin[x], tout[x], 1);
            ans = 0;
            while (res) {
                ans += (res & 1ll);
                res >>= 1;
            }
            cout << ans << '\n';
        }
    }
    
}