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

const int modulo = 1e9 + 7;
const int max_n = 2e3;
const int max_bit = 12;
const int max_mask = (1 << (max_bit + 1));

inline int bit(int mask, int i)
{
    return (mask >> i) & 1;
}

inline void minc(int& x, int y)
{
    x += y;
    if (x >= modulo) x -= modulo;
}

int add_to_mask(int mask, int x)
{
    for (int i = 0; i < x; ++i)
        if (bit(mask, i)) {
            return (1 << x);
        }
    while (bit(mask, x)) {
        mask -= (1 << x);
        ++x;
    }
    return mask + (1 << x);
}

int n, k;
int a[max_n];
int dp[max_n + 1][max_mask][2];

void relax(int i, int mask, int alr_win, int b)
{
    int nmask = add_to_mask(mask, b);
    int nalr_win = alr_win | (nmask >= (1 << k));
    minc(dp[i + 1][nmask][nalr_win], dp[i][mask][alr_win]);
}

int main()
{
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> k;
    --k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < max_mask; ++mask)
            for (int alr_win = 0; alr_win < 2; ++alr_win) {
                if (a[i] == 2 || a[i] == 0) relax(i, mask, alr_win, 0);
                if (a[i] == 4 || a[i] == 0) relax(i, mask, alr_win, 1);
            }

    int ans = 0;
    for (int mask = 0; mask < max_mask; ++mask)
        minc(ans, dp[n][mask][1]);

    cout << ans << endl;

    return 0;
}