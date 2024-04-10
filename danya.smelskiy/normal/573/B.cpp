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
int a[100005], dp[100005], dp2[100005];
int ans;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= dp[i - 1] + 1) dp[i] = dp[i - 1] + 1;
        dp[i] = max(dp[i], max(1, min(a[i], dp[i - 1])));
    }
    for (int i = n; i > 0; --i) {
        if (a[i] >= dp2[i + 1] + 1) dp2[i] = dp2[i + 1] + 1;
        else dp2[i] = max(dp2[i], max(1, min(a[i], dp2[i + 1])));
        ans = max(ans, min(dp[i], dp2[i]));
    }
    cout << ans << '\n';
    
}