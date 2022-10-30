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
int a[200005], b[200005];
int ans = -1e9, ans1, ans2;

inline int get(int x) {
    int l = 1;
    int r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (b[l] >= x) return m - l + 1;
    return 0;
}


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    a[n + 1] = 2e9 + 1;
    for (int i = 1; i <= n + 1; ++i) {
        int cur = (i - 1) * 2 + (n - i + 1) * 3;
        int cur2 = 2 * m + get(a[i]);
        if (cur - cur2 > ans || (cur - cur2 == ans && cur > ans1)) {
            ans = cur - cur2;
            ans1 = cur;
            ans2 = cur2;
        }
    }
    cout << ans1 << ":" << ans2 << '\n';
}