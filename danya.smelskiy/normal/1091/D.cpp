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

long long f[1000005];
int n;

inline long long pw(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1ll) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f[0] = 1;
    for (int i = 1;i <= n; ++i) {
        f[i] = f[i - 1] * 1ll * i;
        f[i] %= md;
    }
    long long res = f[n];
    res *= n;
    res %= md;
    long long last = 1;
    for (int i = n;i > 0; --i) {
        res -= last;
        if (res < 0) res += md;
        last = (last * 1ll * i) % md;
    }
    ++res;
    if (res >= md) res -= md;
    cout << res << endl;
}