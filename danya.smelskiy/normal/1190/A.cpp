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


long long n, m, k;
long long ans, a[100005];


inline long long f(long long x) {
    return (x + k - 1ll) / k;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    int l = 1;
    long long s = 0;
    while (l <= m) {
        ++ans;
        int r = l;
        long long ss = 0;
        while (r <= m && f(a[l] - s) == f(a[r] - s)) {
            ++r;
            ++ss;
        }
        s += ss;
        l = r;
    }
    cout << ans << '\n';
}