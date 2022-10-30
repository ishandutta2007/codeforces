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
long long x;
long long res;


long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        res = gcd(res, x);
    }
    long long ans = 1;
    for (long long i = 2; i * i <= res; ++i) if (res % i == 0) {
        int cur = 0;
        while (res % i == 0) {
            res /= i;
            ++cur;
        }
        ans *= cur + 1;
    }
    if (res > 1) {
        ans *= 2;
    }
    cout << ans << '\n';
    return 0;
}