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
int ta, tb, k;
int a[200005];
int b[200005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (k >= n || k >= m) {
        cout << "-1\n";
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i <= k; ++i) {
        long long x = a[i + 1] + ta;
        int l = 1;
        int r = m;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (b[mid] >= x) r = mid;
            else l = mid + 1;
        }
        l += k - i;
        if (l > m || b[l] < x) {
            cout << "-1\n";
            return 0;
        }
        ans = max(ans, 1ll * b[l] + tb);
    }
    cout << ans << '\n';
    return 0;
}