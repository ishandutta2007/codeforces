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
const long long C = 1e12;

inline long long gcd(long long x, long long y) {
    long long res = 0;
    while (x > 0 && y > 0) {
        if (x > y) x %= y;
        else y %= x;
    }
    return x + y;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long res = 1, res2 = 0;
        vector<long long> v1, v2;
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            v1.push_back(x);
        }
        sort(v1.begin(), v1.end());
        res = v1[0] * v1.back();
        for (long long i = 2; i * i <= res; ++i)
            if (res % i == 0) {
                v2.push_back(i);
                if (res / i != i) v2.push_back(res / i);
            }
        sort(v2.begin(), v2.end());
        if (v1 != v2) cout << "-1\n"; else
        cout << res << '\n';
    }
}