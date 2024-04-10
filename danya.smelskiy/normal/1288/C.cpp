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

long long dp1[1005];
long long dp2[1005];
int n, m;

void solve() {
    dp1[1] = 1;
    dp2[n] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp1[j] += dp1[j - 1];
            dp1[j] %= md;
        }
        for (int j = n - 1; j > 0; --j) {
            dp2[j] += dp2[j + 1];
            dp2[j] %= md;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    solve();
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            res += dp1[i] * dp2[j];
            res %= md;
        }
    }
    cout << res << '\n';
    return 0;
}