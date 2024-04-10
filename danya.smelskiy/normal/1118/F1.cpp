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


int n;
int dp[300005][3];
int ans;
int a[300005];
vector<int> v[300005];

void dfs(int x, int y) {
    ++dp[x][a[x]];
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y) continue;
        dfs(to, x);
        for (int j = 0; j <= 2; ++j)
            dp[x][j] += dp[to][j];
    }
    return;
}

void dfs2(int x, int y) {
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to == y) continue;
        dfs2(to, x);
        if (dp[to][1] && dp[to][2]) continue;
        if (dp[1][1] - dp[to][1] && dp[1][2] - dp[to][2]) continue;
        ++ans;
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << ans << '\n';
    
}