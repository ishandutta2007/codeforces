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
pair<int, int> a[300005];
long long f[300005];

inline long long solve(vector<int> v) {
    sort(v.begin(), v.end());
    int l = 1;
    long long res = 1;
    while (l <= n) {
        int r = l;
        while (r <= n && v[r - 1] == v[l - 1]) ++r;
        res *= f[r - l];
        res %= md;
        l = r;
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = (f[i - 1] * 1ll * i) % md;
    vector<int> v1, v2, v3;
    long long ans = f[n];
    int last = 0;
    sort(a + 1, a + n + 1);
    bool t = false;
    for (int i = 1; i <= n; ++i) {
        v1.push_back(a[i].first);
        v2.push_back(a[i].second);
        if (i == 1 || a[i] != a[i - 1]) ++last;
        if (i > 1 && a[i].second < a[i - 1].second) t = true;
        v3.push_back(last);
    }
    ans -= (solve(v1) + solve(v2)) % md;
    if (ans < 0) ans += md;
    if (!t) ans += solve(v3);
    if (ans >= md) ans -= md;
    cout << ans << '\n';
    return 0;
}