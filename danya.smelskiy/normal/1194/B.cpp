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
int dp1[400005];
int dp2[400005];
string s[400005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            dp1[i] = 0;
        for (int i = 1; i <= m; ++i)
            dp2[i] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.') {
                    ++dp1[i];
                    ++dp2[j + 1];
                }
            }
        }
        int ans = n + m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int cur = dp1[i] + dp2[j];
                if (s[i][j - 1] == '.') --cur;
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}