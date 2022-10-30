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


string s;
int dp[200005][3];
int n;



int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < 3; ++j)
            dp[i][j] = dp[i - 1][j];
        dp[i][(s[i - 1] - 'x')]++;
    }
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        if (l == r - 1) {
            cout << "YES\n";
            continue;
        }
        --l;
        int x = dp[r][0] - dp[l][0];
        int y = dp[r][1] - dp[l][1];
        int z = dp[r][2] - dp[l][2];
        int xx = min({x, y, z});
        x -= xx;
        y -= xx;
        z -= xx;
        if (x > 1 || y > 1 || z > 1) cout << "NO\n";
        else cout << "YES\n";
    }
}