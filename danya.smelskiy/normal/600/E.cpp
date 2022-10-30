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


int n, x, y;
int a[100005];
map<int, int> cnt[100005];
int num[100005];
vector<int> v[100005];
int max_count[100005];
long long ans[100005], ans2[100005];

void add(int x, int y, int z) {
    cnt[x][y] += z;
    if (cnt[x][y] > max_count[x]) {
        max_count[x] = cnt[x][y];
        ans[x] = y;
    } else if (cnt[x][y] == max_count[x]) {
        ans[x] += y;
    }
    return;
}

void dfs(int x, int y) {
    int nxt = x;
    int mx = 0;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y) continue;
        dfs(to, x);
        int xx = num[to];
        if ((int)cnt[xx].size() > mx) {
            mx = (int)cnt[xx].size();
            nxt = xx;
        }
    }
    num[x] = nxt;
    add(nxt, a[x], 1);
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y || num[to] == nxt) continue;
        to = num[to];
        for (auto it: cnt[to]) {
            add(nxt, it.first, it.second);
        }
    }
    ans2[x] = ans[num[x]];
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << ans2[i] << " ";
    cout << '\n';
}