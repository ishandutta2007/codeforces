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
int f[100005], last[100005];
int ans;
int x;
int a[100005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        if (!f[a[i]]) f[a[i]] = i;
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (!f[i]) {
            if (i > 1) ++ans;
            if (i < n) ++ans;
            ++ans;
            continue;
        }
        x = i;
        if (x > 1) {
            if (last[x - 1] < f[x]) ++ans;
        }
        if (x < n) {
            if (last[x + 1] < f[x]) ++ans;
        }
    }
    cout << ans << '\n';
}