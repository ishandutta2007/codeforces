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

int n, m, x, y;
pair<int, int> a[5005];
int q[5005];
int dp[5005];
int ans;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        a[i] = {x, y};
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            q[j] = 0;
        for (int k = 1; k <= m; ++k) if (k != i) {
            q[a[k].first]++;
            q[a[k].second + 1]--;
        }
        for (int k = 1; k <= n; ++k)
            q[k] += q[k - 1];
        int all = 0;
        for (int k = 1; k <= n; ++k) {
            dp[k] = dp[k - 1];
            if (q[k] == 1) ++dp[k];
            if (q[k]) ++all;
        }
        for (int j = 1; j <= m; ++j) if (j != i) {
            int cur = all - (dp[a[j].second] - dp[a[j].first - 1]);
            if (cur > ans) ans = cur;
        }
    }
    cout << ans << '\n';
}