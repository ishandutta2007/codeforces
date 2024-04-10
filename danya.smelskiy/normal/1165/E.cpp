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
const long long md = 998244353;

int n;
long long ans;
long long a[200005], b[200005];
pair<long long, int> c[200005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        long long s = i * 1ll * (n - i + 1ll);
        s *= a[i];
        c[i] = make_pair(s, i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    sort(c + 1, c + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        c[i].first %= md;
        ans += c[i].first * b[n - i + 1];
        ans %= md;
    }
    cout << ans << '\n';
    return 0;
}