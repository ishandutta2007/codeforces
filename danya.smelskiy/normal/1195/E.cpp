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
int a, b;
long long last, x, y, z;
int aa[3005][3005];
pair<int, int> q[3005];
int dp[3005][3005];
long long ans;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> b;
    cin >> last >> x >> y >> z;
    aa[1][1] = last;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i + j == 2) continue;
            last = (last * x + y) % z;
            aa[i][j] = last;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = 0;
        for (int j = 1; j <= m; ++j) {
            while (l <= r && q[r].first >= aa[i][j]) --r;
            q[++r] = {aa[i][j], j};
            while (l <= r && q[l].second <= j - b) ++l;
            if (j >= b) dp[i][j - b + 1] = q[l].first;
        }
    }
    for (int j = 1; j <= m - b + 1; ++j) {
        int l = 1, r = 0;
        for (int i = 1; i <= n; ++i) {
            while (l <= r && q[r].first >= dp[i][j]) --r;
            q[++r] = {dp[i][j], i};
            while (l <= r && q[l].second <= i - a) ++l;
            if (i >= a) ans += q[l].first;
        }
    }
    cout << ans << '\n';
    return 0;
}