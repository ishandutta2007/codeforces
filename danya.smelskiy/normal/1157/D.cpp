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
long long ans[100005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    long long s = (m * (m + 1ll)) / 2ll;
    if (n < s) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        ans[i] = i;
        n -= ans[i];
    }
    s = n / m;
    n %= m;
    for (int i = 1; i <= m; ++i) {
        ans[i] += s;
    }
    if (n > 0) {
    if (n < m - 1 || ans[1] > 1) {
        for (int i = m; i > 0 && n > 0; --i) {
            ++ans[i];
            --n;
        }
    } else {
        for (int i = 3; i <= m; ++i)
            ++ans[i], --n;
        ++ans[m], --n;
    }
    }
    bool t = false;
    for (int i = 1; i <= m; ++i) {
        if (ans[i] <= 0) t = true;
        if (i > 1) {
            if (ans[i] > ans[i - 1] + ans[i - 1]) t = true;
            if (ans[i] <= ans[i - 1]) t = true;
        }
    }
    if (n > 0) t = true;
    if (t) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 1; i <= m; ++i)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}