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
const long long mx = 500;


long long dp[mx + 5][mx + 5];
long long a[500005];

void upd(int x, int y) {
    a[x] += y;
    for (int i = 1; i < mx; ++i)
        dp[i][x % i] += y;
    return;
}

long long get(int x, int y) {
    long long res = 0;
    if (x >= mx) {
        for (int i = y; i <= 500000; i += x)
            res += a[i];
        return res;
    }
    return dp[x][y];
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    int tp, x, y;
    while (t--) {
        cin >> tp >> x >> y;
        if (tp == 1) {
            upd(x, y);
        } else cout << get(x, y) << '\n';
    }
    return 0;
}