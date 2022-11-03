#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;

const int max_n = 19;
const int max_mask = (1 << max_n);

inline int bit(int mask, int i)
{
    return (mask >> i) & 1;
}

int n, m;
int a[max_n][max_n];
ll dp[max_mask][max_n];
int bits[max_mask];
int lowest[max_mask];
ll ans;

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        a[v1][v2] = a[v2][v1] = 1;
    }
    
    for (int mask = 0; mask < (1 << n); ++mask) {
        bits[mask] = 0;
        for (int i = 0; i < n; ++i)
            bits[mask] += bit(mask, i);
        lowest[mask] = 0;
        for (int i = 0; i < n; ++i)
            if (bit(mask, i)) {
                lowest[mask] = i;
                break;
            }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = 1;
    for (int mask = 0; mask < (1 << n); ++mask)
        for (int finish = 0; finish < n; ++finish) 
            for (int nx = lowest[mask]; nx < n; ++nx)
                if (a[finish][nx] && !bit(mask, nx)) {
                    dp[mask + (1 << nx)][nx] += dp[mask][finish];
                }

    ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (bits[mask] > 2) {
            for (int finish = 0; finish < n; ++finish)
                if (a[finish][lowest[mask]])
                    ans += dp[mask][finish];
        }
    }
    ans >>= 1;
    
    cout << ans << endl;
    
    return 0;
}