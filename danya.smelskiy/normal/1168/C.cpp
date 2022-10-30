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
int a[300005];
int dp[300005][20], last[30];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j < 20; ++j) {
            dp[i][j] = n + 1;
        }
    }
    for (int i = 0; i < 20; ++i)
        last[i] = n + 1;
    for (int i = n; i > 0; --i) {
        int x = a[i];
        for (int j = 0; j < 20; ++j)
            if ((x & (1 << j))) dp[i][j] = i; else {
                for (int k = 0; k < 20; ++k) if ((x & (1 << k))) {
                    int pos = last[k];
                    if (dp[pos][j] < dp[i][j]) dp[i][j] = dp[pos][j];
                }
            }
        for (int j = 0; j < 20; ++j)
            if ((x & (1 << j))) last[j] = i;
    }
    int l, r, x;
    while (m--) {
        cin >> l >> r;
        x = a[r];
        bool t = false;
        for (int i = 0; i < 20; ++i)
            if ((x & (1 << i)) && dp[l][i] <= r) t = true;
        cout << (t ? "Shi" : "Fou") << '\n';
    }
    return 0;
}