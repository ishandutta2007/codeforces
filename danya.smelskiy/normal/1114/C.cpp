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



long long n, m;


inline long long get(long long x, long long y) {
    long long res = 0;
    while (x) {
        res += x / y;
        x /= y;
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    long long ans = 1e18;
    for (long long i = 2; i * i <= m; ++i) if (m % i == 0) {
        long long c = 0;
        while (m % i == 0) {
            ++c;
            m /= i;
        }
        ans = min(ans, get(n, i) / c);
    }
    if (m > 1) ans = min(ans, get(n, m));
    cout << ans << '\n';
}