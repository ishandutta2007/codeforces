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
const long long md = 1e9 + 7;

int n, x;
vector<int> v[1000005];
long long dp[1000005];
long long ans;

inline void init() {
    for (int i = 1; i <= 1e6; ++i) {
        for (int j = i; j <= 1e6; j += i)
            v[j].push_back(i);
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    cin >> n;
    dp[0] = 1;
    int y;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = v[x].size() - 1; j >= 0; --j) {
            y = v[x][j];
            dp[y] += dp[y - 1];
            if (dp[y] >= md) dp[y] -= md;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 1e6; ++i)
        ans += dp[i];
    ans %= md;
    cout << ans << '\n';
}