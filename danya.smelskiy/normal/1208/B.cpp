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
int a[2005], b[2005];
map<int, int> mt;
int last;
int cnt[2005];
int ans;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || b[i] != b[i - 1]) mt[b[i]] = ++last;
    }
    for (int i = 1; i <= n; ++i)
        a[i] = mt[a[i]];
    ans = n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= last; ++j)
            cnt[j] = 0;
        bool t = false;
        for (int j = 1; j <= i; ++j) {
            ++cnt[a[j]];
            if (cnt[a[j]] == 2) {
                t = true;
                break;
            }
        }
        if (t) break;
        ans = min(ans, n - i);
        for (int j = n; j > 0; --j) {
            ++cnt[a[j]];
            if (cnt[a[j]] == 2) {
                break;
            }
            ans = min(ans, j - i - 1);
        }
    }
    cout << ans << '\n';
}