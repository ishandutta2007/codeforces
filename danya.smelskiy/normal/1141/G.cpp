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


int n, m, x, y;
vector<pair<int, int> > v[200005];
int c;
int b[200005];
int ans[200005];

void dfs(int x, int y, int z) {
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y) continue;
        int r = v[x][i].second;
        ++z;
        if (z > c) z = 1;
        ans[r] = z;
        dfs(to, x, z);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(make_pair(y, i));
        v[y].push_back(make_pair(x, i));
    }
    for (int i = 1; i <= n; ++i)
        b[i] = (int)v[i].size();
    sort(b + 1, b + n + 1);
    c = b[n - m];
    dfs(1, 0, 0);
    cout << c << '\n';
    for (int i = 1; i < n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}