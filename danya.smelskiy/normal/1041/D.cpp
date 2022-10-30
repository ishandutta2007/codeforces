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



long long n, m, sz;
pair<long long, long long> a[200005];
pair<long long, long long> b[200005];
long long p[200005];

long long get(long long x) {
    int l = 1;
    int r = sz;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (b[mid].second <= x) l = mid;
        else r = mid - 1;
    }
    long long res = 0;
    if (b[l].second <= x) {
        res += p[l];
        ++l;
    }
    if (l <= sz && b[l].first <= x) res += x - b[l].first + 1;
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        ++a[i].first;
    }
    sort(a + 1, a + n + 1);
    b[++sz] = make_pair(-1e9, a[1].first - 1);
    for (int i = 2; i <= n; ++i)
        b[++sz] = make_pair(a[i - 1].second + 1, a[i].first - 1);
    b[++sz] = make_pair(a[n].second + 1, 2e9);
    for (int i = 1; i <= sz; ++i)
        p[i] = p[i - 1] + b[i].second - b[i].first + 1ll;
    long long ans = m;
    for (int i = 1; i <= n; ++i) {
        long long l = a[i].first;
        long long r = 2e9;
        while (l < r) {
            long long mid = (l + r) / 2ll;
            if (get(mid) - get(a[i].first - 1) >= m) r = mid;
            else l = mid + 1ll;
        }
        ans = max(ans, l - a[i].first + 1ll);
    }
    cout << ans << '\n';
}