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


int n, m;
int a[1000005], dp1[1000005], dp2[1000005], dp3[1000005];
long long ans;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= m + 1; ++i) {
        dp1[i] = 1e9;
        dp2[i] = -1e9;
    }
    int x;
    int mn = 1e9;
    for (int i = n; i > 0; --i) {
        x = a[i];
        if (mn < x && mn < dp1[x]) dp1[x] = mn;
        if (x < mn) mn = x;
    }
    int mx = -1e9;
    for (int i = 1; i <= n; ++i) {
        x = a[i];
        if (mx > x && mx > dp2[x]) dp2[x] = mx;
        if (x > mx) mx = x;
    }
    for (int i = m; i > 0; --i) {
        dp3[i] = dp1[i];
        if (dp1[i + 1] < dp1[i]) dp1[i] = dp1[i + 1];
    }
    for (int i = m; i > 0; --i) {
        if (dp2[i + 1] > dp2[i]) dp2[i] = dp2[i + 1];
    }
    int l, r;
    for (int i = 1; i <= m; ++i) {
        l = i;
        r = m;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (dp1[mid + 1] >= i && dp2[mid + 1] <= mid) r = mid;
            else l = mid + 1;
        }
        if (dp1[r + 1] >= i && dp2[r + 1] <= r) ans += m - r + 1;
        if (dp3[i] < i) break;
    }
    cout << ans << '\n';
    return 0;
}