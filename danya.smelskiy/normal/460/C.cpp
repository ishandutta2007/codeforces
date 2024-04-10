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
# define int long long
using namespace std;



int n, m, w;
int a[200005];
int b[200005];
int q[200005];

inline bool f(int mid) {
    for (int i = 1; i <= n; ++i) {
        b[i] = max(0ll, mid - a[i]);
        q[i] = 0;
    }
    int mm = m;
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        last += q[i];
        b[i] -= last;
        if (b[i] > 0) {
            if (b[i] > mm) return false;
            mm -= b[i];
            q[i + 1] += b[i];
            q[i + w] -= b[i];
        }
    }
    return true;
}


main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1;
    int r = 2e9;
    while (l < r) {
        long long mid = (l + r + 1ll) >> 1;
        if (f(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}