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


long long n;
pair<int, int> a[2005];
map<pair<int, int>, int> m;


inline int gcd(int x, int y) {
    while (x > 0 && y > 0) {
        if (x > y) x %= y;
        else y %= x;
    }
    if (x + y == 0) return 1;
    return x + y;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    long long ans = (n * 1ll * (n - 1ll) * 1ll * (n - 2ll)) / 6ll;
    for (int i = 1; i <= n; ++i) {
        m.clear();
        for (int j = 1; j < i; ++j) {
            int x = a[i].first - a[j].first;
            int y = a[i].second - a[j].second;
            bool t1 = (x < 0);
            bool t2 = (y < 0);
            x = abs(x);
            y = abs(y);
            int z = gcd(x, y);
            x /= z;
            y /= z;
            if (t1) x *= -1;
            if (t2) y *= -1;
            ++m[{x, y}];
        }
        for (int j = i + 1; j <= n; ++j) {
            int x = a[j].first - a[i].first;
            int y = a[j].second - a[i].second;
            bool t1 = (x < 0);
            bool t2 = (y < 0);
            x = abs(x);
            y = abs(y);
            int z = gcd(x, y);
            x /= z;
            y /= z;
            if (t1) x *= -1;
            if (t2) y *= -1;
            ans -= m[{x, y}];
        }
    }
    cout << ans << '\n';
    
}