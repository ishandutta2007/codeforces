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


int n;
int a[200005];
int b[200005];
int m;
int lft[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        m = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == 1 || a[i] != a[i - 1]) b[++m] = a[i];
        }
        n = m;
        for (int i = 1; i <= n; ++i)
            a[i] = b[i];
        for (int i = 1; i <= n; ++i) {
            int l = i - 1;
            if (i > 1 && a[i] % a[i - 1] == 0) l = lft[i - 1];
            while (l && a[i] % a[l] == 0) --l;
            lft[i] = l;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, a[i]);
            int l = lft[i];
            if (l) ans = max(ans, a[i] + a[l]);
            while (l) {
                int r = lft[l];
                if (a[i] % a[l] == 0) {
                    --l;
                    continue;
                }
                if (!r) {
                    ans = max(ans, a[i] + a[l]);
                    --l;
                    continue;
                }
                if (a[i] % a[r]) {
                    ans = max(ans, a[i] + a[l] + a[r]);
                    break;
                }
                --r;
                while (r) {
                    if (a[l] % a[r] == 0 || a[i] % a[r] == 0) {
                        --r;
                        continue;
                    }
                    ans = max(ans, a[i] + a[l] + a[r]);
                    break;
                }
                --l;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}