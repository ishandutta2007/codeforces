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
int x;
int mx[2000005];
int ans;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        mx[x] = x;
    }
    for (int i = 1; i <= 2e6; ++i)
        if (!mx[i]) mx[i] = mx[i - 1];
    for (int i = 2; i <= 1e6; ++i) if (mx[i] == i) {
        for (int j = i + i - 1; j <= 2e6; j += i) {
            if (mx[j] >= j + 1 - i) ans = max(ans, mx[j] - (j + 1 - i));
        }
    }
    cout << ans << '\n';
    return 0;
}