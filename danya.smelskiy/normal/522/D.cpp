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
int a[500005];
int f[500005];
int ans[500005];
vector<pair<int, int> > v[500005];
map<int, int> last;

void update(int x, int y) {
    while (x <= n) {
        f[x] = min(f[x], y);
        x = (x | (x + 1));
    }
    return;
}

int get(int x) {
    int res = 1e9;
    while (x > 0) {
        res = min(res, f[x]);
        x = (x & (x + 1)) - 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = 1e9;
    }
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        v[x].push_back({y, i});
    }
    for (int i = n; i > 0; --i) {
        x = a[i];
        if (last[x]) update(last[x], last[x] - i);
        last[x] = i;
        for (int j = 0; j < v[i].size(); ++j)
            ans[v[i][j].second] = get(v[i][j].first);
    }
    for (int i = 1; i <= m; ++i)
        cout << (ans[i] < 1e9 ? ans[i] : -1) << '\n';
}