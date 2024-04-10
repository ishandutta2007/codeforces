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


long long b[100];
long long a[100];
long long ans;

inline int get(int x) {
    if (x == 1 || x == 4 || x == 7) return 0;
    if (x == 2 || x == 6) return 1;
    return 2;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 1; i <= 7; ++i) {
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];
        long long cur = 0;
        bool t = false;
        for (int j = i; j <= 7; ++j) {
            int x = get(j);
            if (!b[x]) {
                t = true;
                break;
            }
            --b[x];
            ++cur;
        }
        ans = max(ans, cur);
        if (t) continue;
        long long cur2 = min({b[0] / 3ll, b[1] / 2ll, b[2] / 2ll});
        cur += cur2 * 7ll;
        b[0] -= 3 * cur2;
        b[1] -= 2 * cur2;
        b[2] -= 2 * cur2;
        for (int j = 1; j <= 7; ++j) {
            int x = get(j);
            if (!b[x]) {
                t = true;
                break;
            }
            --b[x];
            ++cur;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}