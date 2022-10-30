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
int a[1005][1005];
int b[1005][1005];
int dp[1005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        int x;
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            cur ^= (a[i][j] ^ x);
            dp[j] ^= (a[i][j] ^ x);
        }
        if (cur) {
            cout << "No\n";
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i)
        if (dp[i]) {
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
    return 0;
}