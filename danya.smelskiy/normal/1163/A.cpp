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
bool used[1005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n && m; ++i)
        if (i & 1) {
            --m;
            used[i] = true;
        }
    for (int i = 1; i <= n && m; ++i)
        if (!(i & 1)) {
            --m;
            used[i] = true;
        }
    int ans = 0;
    used[0] = true;
    for (int i = 1; i <= n; ++i)
        if (!used[i] && used[i - 1]) ++ans;
    if (!used[1] && !used[n]) {
        if (ans > 1) --ans;
    }
    cout << ans << '\n';
}