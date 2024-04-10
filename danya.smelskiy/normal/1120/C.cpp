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



int n, a, b;
string s, ss;
int p[5005];
int dp[5005];
int zf[5005];
int last[5005];

void calc_zf(int n) {
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        zf[i] = 0;
        if (i <= r) zf[i] = min(zf[i - l], r - i + 1);
        while (i + zf[i] < n && ss[zf[i]] == ss[zf[i] + i]) ++zf[i];
        if (i + zf[i] - 1 > r) {
            l = i;
            r = i + zf[i] - 1;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    cin >> s;
    s = "#" + s;
    int cur;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a;
        ss = "";
        for (int j = i; j > 0; --j)
            ss += s[j];
        calc_zf((int)ss.size());
        for (int j = 0; j < ss.size(); ++j)
            p[i - j] = zf[j];
        for (int j = 1; j <= i; ++j)
            last[j] = 1e9;
        for (int j = 1; j < i; ++j)
            if (j < last[p[j]]) last[p[j]] = j;
        for (int j = i - 1; j > 0; --j)
            if (last[j + 1] < last[j]) last[j] = last[j + 1];
        for (int j = i; j > 0; --j) if (last[i - j + 1] < j) {
            cur = dp[j - 1] + b;
            if (cur < dp[i]) dp[i] = cur;
        }
    }
    cout << dp[n] << '\n';
}