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
int p[200005];
int sz[200005];
long long ans[200005];
pair<pair<int, int>, int> e[200005];

inline bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
    return x.second < y.second;
}

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> e[i].first.first >> e[i].first.second >> e[i].second;
    }
    sort(e + 1, e + n, cmp);
    for (int i = 1; i <= n; ++i)
        p[i] = i, sz[i] = 1;
    for (int i = 1; i < n; ++i) {
        int x, y;
        x = e[i].first.first;
        y = e[i].first.second;
        x = get(x);
        y = get(y);
        ans[i] = ans[i - 1] + sz[x] * 1ll * sz[y];
        p[y] = x;
        sz[x] += sz[y];
    }
    while (m--) {
        int x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (e[mid].second <= x) l = mid;
            else r = mid - 1;
        }
        cout << ans[l] << " ";
    }
    cout << '\n';
    return 0;
}