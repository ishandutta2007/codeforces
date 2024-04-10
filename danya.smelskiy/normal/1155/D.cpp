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


long long n, m, ans;
long long a[300005];
long long dp[300005], dp2[300005];

void solve(int l, int r) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    long long s1 = 0;
    s1 = max(s1, dp[mid]);
    long long s = 0;
    for (int i = mid; i >= l; --i) {
        s += a[i] * m;
        s1 = max(s1, s + dp[i - 1]);
    }
    s = 0;
    long long s2 = 0;
    s2 = max(s2, dp2[mid + 1]);
    for (int i = mid + 1; i <= r; ++i) {
        s += a[i] * m;
        s2 = max(s2, s + dp2[i + 1]);
    }
    ans = max(ans, s1 + s2);
    if (l == r) return;
    solve(l, mid);
    solve(mid + 1, r);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = max(0ll, dp[i - 1] + a[i]);
    }
    for (int i = n; i > 0; --i) {
        dp2[i] = max(0ll, dp2[i + 1] + a[i]);
        ans = max(ans, dp2[i]);
    }
    solve(1, n);
    cout << ans << '\n';
}