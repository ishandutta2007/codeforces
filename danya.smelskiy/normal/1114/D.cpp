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
int a[5005];
short dp[5005][5005][2];

void upd(short x, short y, short z, short xx, short yy, short zz, short cur = 0) {
    cur += dp[xx][yy][zz];
    if (cur < dp[x][y][z]) dp[x][y][z] = cur;
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int len = 2; len <= n; ++len) {
        for (int j = len; j <= n; ++j) {
            int i = j - len + 1;
            dp[i][j][0] = 1e4;
            if (a[i] == a[i + 1]) upd(i, j, 0, i + 1, j, 0);
            if (a[i] == a[j]) upd(i, j, 0, i + 1, j, 1);
            upd(i, j, 0, i + 1, j, 0, 1);
            upd(i, j, 0, i + 1, j, 1, 1);
            dp[i][j][1] = 1e4;
            if (a[j] == a[j - 1]) upd(i, j, 1, i, j - 1, 1);
            if (a[j] == a[i]) upd(i, j, 1, i, j - 1, 0);
            upd(i, j, 1, i, j - 1, 0, 1);
            upd(i, j, 1, i, j - 1, 1, 1);
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << '\n';
}