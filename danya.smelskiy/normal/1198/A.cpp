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
long long a[400005];
pair<long long, long long> b[400005];
int sz;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    m *= 8;
    m /= n;
    if (m > 35) m = (1ll << 32ll);
    else m = (1ll << m);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) if (i == 1 || a[i] != a[i - 1]) b[++sz] = {a[i], 1};
    else b[sz].second++;
    n = sz;
    for (int i = 1; i <= n; ++i)
        b[i].second += b[i - 1].second;
    long long ans = 1e18, cur;
    for (int i = 1; i <= n; ++i) {
        cur = b[i - 1].second;
        if (i + m - 1 <= n) cur += b[n].second - b[i + m - 1].second;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}