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
long long a[100005], b[100005];
pair<long long, long long> c[100005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = make_pair(b[i], i);
    }
    sort(c + 1, c + n + 1);
    int last = 1;
    for (int i = 1; i <= m; ++i) {
        long long x, y;
        cin >> x >> y;
        long long z = min(a[x], y);
        long long cur = 0;
        cur += z * b[x];
        y -= z;
        a[x] -= z;
        while (last <= n && y > 0) {
            x = c[last].second;
            if (!a[x]) {
                ++last;
                continue;
            }
            z = min(a[x], y);
            y -= z;
            a[x] -= z;
            cur += b[x] * z;
        }
        if (y) cur = 0;
        cout << cur << '\n';
    }
    
}