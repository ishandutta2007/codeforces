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


long long n, a, b;
long long d[400005];


inline long long f(long long x) {
    long long res = x;
    res *= (x + 1ll);
    res /= 2ll;
    return res;
}

void dij() {
    for (int i = 0; i <= n; ++i)
        d[i] = 1e9;
    d[0] = 0;
    set<pair<int, int> > s;
    s.clear();
    s.insert(make_pair(0, 0));
    int len;
    while (!s.empty()) {
        int x = s.begin()->second;
        s.erase(s.begin());
        if (x - b >= 0) {
            len = d[x];
            if (len < d[x - b]) {
                s.erase(make_pair(d[x - b], x - b));
                d[x - b] = len;
                s.insert(make_pair(d[x - b], x - b));
            }
        }
        if (x + a <= n) {
            len = max(d[x], x + a);
            if (len < d[x + a]) {
                s.erase(make_pair(d[x + a], x + a));
                d[x + a] = len;
                s.insert(make_pair(d[x + a], x + a));
            }
        }
    }
    return;
}

inline long long gcd(long long x, long long y) {
    while (x > 0 && y > 0) {
        if (x > y) x %= y;
        else y %= x;
    }
    return x + y;
}

inline long long get(int x, int y) {
    ++x;
    long long z = x / y;
    long long res = f(z);
    res *= y;
    while ((x + y - 1 ) / y > z) {
        res += (x / y) + 1ll;
        --x;
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    long long res = 0;
    if (n >= 400000) {
        res += get(n, gcd(a, b));
        res -= get(400000, gcd(a, b));
    }
    n = min(n, 400000 * 1ll);
    dij();
    for (int i = 0; i <= n; ++i)
        if (d[i] < 1e9) res += n - d[i] + 1;
    cout << res << '\n';
}