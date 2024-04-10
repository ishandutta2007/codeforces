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


int n, m, k;
pair<pair<int, int>, long long> e[1000005];
int num[200005];
int all;
int onum[805];
long long d[805][805];

inline bool cmp(pair<pair<int, int>, long long> x, pair<pair<int, int>, long long> y) {
    return x.second < y.second;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].first.first >> e[i].first.second >> e[i].second;
    }
    sort(e + 1, e + m + 1, cmp);
    m = min(m, k);
    for (int i = 1; i <= m + m; ++i)
        for (int j = 1; j <= m + m; ++j)
            if (i != j) d[i][j] = 1e18;
    for (int i = 1; i <= m; ++i) {
        int x = e[i].first.first;
        int y = e[i].first.second;
        if (!num[x]) {
            num[x] = ++all;
            onum[all] = x;
        }
        if (!num[y]) {
            num[y] = ++all;
            onum[all] = y;
        }
        x = num[x];
        y = num[y];
        d[x][y] = d[y][x] = e[i].second;
    }
    n = all;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    all = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            e[++all] = {{i, j}, d[i][j]};
        }
    }
    sort(e + 1, e + all + 1, cmp);
    cout << e[k].second << '\n';
    return 0;
}