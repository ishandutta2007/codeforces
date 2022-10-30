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



long long a, b;
long long ans = 3e18;
long long pos;

inline void check(long long x) {
    long long k = (x - a % x) % x;
    long long xx = a + k;
    long long yy = b + k;
    while (xx > 0 && yy > 0) {
        if (xx > yy) xx %= yy;
        else yy %= xx;
    }
    long long res = (a + k) * (b + k) / (xx + yy);
    if (res < ans) {
        ans = res;
        pos = k;
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (b - a <= 1) {
        cout << 0 << '\n';
        return 0;
    }
    ans = a * b;
    pos = 0;
    long long x = b - a;
    for (long long i = 2; i * i <= x; ++i) if (x % i == 0) {
        check(i);
        check(x / i);
    }
    if (x > 1ll) check(x);
    cout << pos << '\n';
}