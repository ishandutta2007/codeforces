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

const long long md = 998244353;

int n;
vector<int> v[200005];
long long dp[200005][3];
long long dp2[200005][2];
long long d[3];

void dfs(int x) {
    if ((int)v[x].size() == 0) {
        dp2[x][0] = 1, dp2[x][1] = 1;
        return;
    }
    dp[x][0] = 1;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to);
    }
    long long cur;
    int z;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        d[0] = d[1] = d[2] = 0;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                cur = dp[x][j] * dp2[to][k];
                cur %= md;
                z = j + k;
                if (z > 2) z = 2;
                d[z] += cur;
                if (d[z] >= md) d[z] -= md;
            }
        }
        for (int j = 0; j < 3; ++j)
            dp[x][j] = d[j];
    }
    dp2[x][0] = dp[x][0] + dp[x][2];
    if (dp2[x][0] >= md) dp2[x][0] -= md;
    dp2[x][1] = dp[x][1] + dp[x][2];
    if (dp2[x][1] >= md) dp2[x][1] -= md;
}


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    long long res = dp2[1][0];
    cout << res << '\n';
}