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
vector<int> v[300005];
int used[(1 << 9)];
int pw[100];


pair<int, int> f(int mid) {
    for (int i = 0; i < (1 << m); ++i)
        used[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j)
            if (v[i][j] >= mid) cur += pw[j];
        used[cur] = i;
    }
    for (int i = 0; i < (1 << m); ++i) if (used[i])
        for (int j = i; j < (1 << m); ++j) if (used[j])
            if ((i | j) == ((1 << m) - 1)) return {used[i], used[j]};
    return make_pair(0, 0);
}

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int j = 0; j < m; ++j)
        pw[j] = (1 << j);
    for (int i = 1; i <= n; ++i) {
        v[i].resize(m);
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];
    }
    int l = 0;
    int r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (f(mid).first) l = mid;
        else r = mid - 1;
    }
    pair<int, int> res = f(l);
    cout << res.first << " " << res.second << '\n';
    return 0;
}