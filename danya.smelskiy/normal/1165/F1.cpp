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
long long a[200005];
bool used[200005];
vector<int> v[400005];
pair<int, int> b[200005];

inline bool f(long long mid) {
    for (int i = 1; i <= n; ++i)
        used[i] = false;
    long long s = 0;
    long long ss = 0;
    for (int i = mid; i > 0; --i) {
        for (int j = 0; j < (int)v[i].size(); ++j) {
            int x = v[i][j];
            if (!used[x]) {
                s += a[x];
                used[x] = true;
            }
        }
        if (s) {
            --s;
            ++ss;
        }
    }
    long long s2 = 0;
    for (int i = 1; i <= n; ++i)
        s2 += a[i];
    return (mid - ss) >= (s2 - ss) * 2ll;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first >> b[i].second;
        v[b[i].first].push_back(b[i].second);
    }
    int l = 1;
    int r = 400000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}