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
long long s;
pair<long long, long long> a[300005];


bool f(long long mid) {
    vector<long long> vv;
    long long ss = s;
    for (int i = 1; i <= n; ++i) {
        if (a[i].second < mid) {
            ss -= a[i].first;
            continue;
        }
        ss -= a[i].first;
        vv.push_back(max(mid, a[i].first) - a[i].first);
    }
    int l = (n + 1) / 2;
    if (vv.size() < l) return false;
    sort(vv.begin(), vv.end());
    for (int i = 0; i < l; ++i)
        ss -= vv[i];
    return ss >= 0;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        long long l = 0;
        long long r = s;
        while (l < r) {
            long long mid = (l + r + 1ll) / 2ll;
            if (f(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << '\n';
    }
    return 0;
}