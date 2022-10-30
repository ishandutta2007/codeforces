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
int a[200005], dp[200005], dp2[200005], pred[200005];
int ans[200005];
int l;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp2[i] = 1;
        if (i > 1 && a[i - 1] > a[i]) dp2[i] += dp2[i - 1];
    }
    dp[0] = 1e9;
    a[0] = -1e9;
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1;
        if (a[i - 1] < a[i]) {
            dp[i] = dp[i - 1];
            pred[i] = i - 1;
        }
        l = i - dp2[i - 1];
        if (dp[l - 1] > a[l] && a[l - 1] < a[i]) {
            if (a[i - 1] > dp[i]) {
                dp[i] = a[i - 1];
                pred[i] = l - 1;
            }
        }
        if (l < i - 1 && dp[l] > a[l + 1] && a[l] < a[i]) {
            if (a[i - 1] > dp[i]) {
                dp[i] = a[i - 1];
                pred[i] = l;
            }
        }
    }
//    for (int i = 1; i <= n; ++i)
  //      cout << dp[i] << " ";
    //cout << '\n';
    int last = -1;
    if (dp[n] != -1) last = n;
    else {
        for (int i = n - 1; i > 0; --i) {
            if (dp[i] > a[i + 1]) {
                last = i;
                break;
            }
            if (a[i] <= a[i + 1]) break;
        }
    }
    if (last == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while (last) {
        ans[last] = 1;
        last = pred[last];
    }
    for (int i = 1; i <= n; ++i)
        cout << 1 - ans[i] << " ";
    cout << '\n';
}