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


long long a[1005];
long long b[1005];
int n;


inline bool check(long long x) {
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
        if (b[i] == a[1]) b[i] += x;
        else if (b[i] == a[1] + x + x) b[i] -= x;
        if (i > 1 && b[i] != b[i - 1]) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long ans = 1e18;
    if (check(a[n] - a[1])) ans = a[n] - a[1];
    if (check((a[n] - a[1]) / 2ll)) ans = min(ans, (a[n] - a[1]) / 2ll);
    if (ans == 1e18) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}