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
int last;
map<pair<int, int>, int> used;
int f[300005];
int all;
int ans[300005];
int dp[300005];
int lft[300005], rght[300005];
int p[300005];
vector<pair<int, int> > q[300005];
int pos[300005];

int gcd(int x, int y) {
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    int res = 0;
    while (x > 0 && y > 0) {
        if (x > y) x %= y;
        else y %= x;
    }
    res = x + y;
    if (res == 0) return 1;
    return res;
}

void update(int x, int y) {
    while (x <= last) {
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

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        vector<pair<int, int> > q;
        for (int j = 1; j <= c; ++j) {
            int x, y;
            cin >> x >> y;
            q.push_back({x, y});
        }
        q.push_back(q[0]);
        vector<int> qq;
        for (int j = 1; j < (int)q.size(); ++j) {
            int x = q[j].first - q[j - 1].first;
            int y = q[j].second - q[j - 1].second;
            int z = gcd(x, y);
            x /= z;
            y /= z;
            if (!used.count({x, y})) used[{x, y}] = ++all;
            z = used[{x, y}];
            qq.push_back(z);
        }
        sort(qq.begin(), qq.end());
        int cc = 0;
        lft[i] = last + 1;
        for (int j = 0; j < (int)qq.size(); ++j) {
            if (j == 0 || qq[j] != qq[j - 1]) {
                ++last;
                p[last] = qq[j];
                ++cc;
            }
        }
        dp[i] = dp[i - 1] + c;
        rght[i] = last;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        q[rght[y]].push_back({lft[x], i});
    }
    for (int i = 1; i <= last; ++i) {
        int x = p[i];
        if (pos[x]) update(pos[x], -1);
        pos[x] = i;
        update(i, 1);
        for (int j = 0; j < (int)q[i].size(); ++j) {
            int l = q[i][j].first;
            ans[q[i][j].second] += get(i) - get(l - 1);
        }
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';
    return 0;
}