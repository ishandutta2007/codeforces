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


long long ans;
int n;
long long w[300005];
vector<pair<int, long long> > v[300005];


pair<long long, long long> dfs(int x, int y) {
    long long res = w[x];
    long long mx = w[x];
    ans = max(ans, mx);
    for (int i = 0;i < v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y) continue;
        pair<long long, long long> cur = dfs(to, x);
        ans = max(ans, mx + cur.first - v[x][i].second);
        mx = max(mx, cur.second - v[x][i].second + w[x]);
        ans = max(ans, mx);
        res = max(res, w[x] + cur.first - v[x][i].second);
    }
    return make_pair(res, mx);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n; ++i) {
        cin >> w[i];
    }
    int x, y;
    long long z;
    for (int i = 1;i < n; ++i) {
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    dfs(1, 0);
    cout << ans << '\n';
}